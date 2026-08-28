#include <utility>
#include <fstream>
#include <memory>
#include <string>
#include <vector>

#include <openreport/dataset/DataSet.hpp>
#include <openreport/actions/LoadCsvAction.hpp>

namespace {

std::vector<std::string> splitSimpleCsvLine(const std::string& line)
{
    std::vector<std::string> fields;
    std::size_t fieldStart = 0;

    while (true)
    {
        const auto comma = line.find(',', fieldStart);

        if (comma == std::string::npos)
        {
            fields.push_back(line.substr(fieldStart));
            break;
        }

        fields.push_back(line.substr(fieldStart, comma - fieldStart));
        fieldStart = comma + 1;
    }

    return fields;
}

void removeTrailingCarriageReturn(std::string& line)
{
    if (!line.empty() && line.back() == '\r')
    {
        line.pop_back();
    }
}

} // namespace


namespace openreport {

LoadCsvAction::LoadCsvAction(std::filesystem::path csvPath)
    : csvPath_(std::move(csvPath))
{
}

std::string LoadCsvAction::name() const
{
    return "Load CSV";
}

ActionResult LoadCsvAction::execute(ActionContext& context)
{
    std::ifstream input{csvPath_};

    if (!input.is_open())
    {
        return ActionResult::failure(
            "Unable to open CSV file: " + csvPath_.string()
        );
    }

    std::string headerLine;

    if (!std::getline(input, headerLine))
    {
        return ActionResult::failure("CSV file is empty.");
    }

    removeTrailingCarriageReturn(headerLine);
    auto columnNames = splitSimpleCsvLine(headerLine);

    std::vector<DataSet::Row> rows;
    std::string line;

    while (std::getline(input, line))
    {
        removeTrailingCarriageReturn(line);
        rows.push_back(splitSimpleCsvLine(line));
    }

    context.data = std::make_shared<DataSet>(
        std::move(columnNames),
        std::move(rows)
    );

    return ActionResult::success("CSV file loaded.");
}

} // namespace openreport