#include <cassert>
#include <filesystem>
#include <memory>

#include <openreport/actions/ActionResult.hpp>
#include <openreport/dataset/DataSet.hpp>
#include <openreport/actions/LoadCsvAction.hpp>

void testLoadCsvActionMissingFile()
{
    openreport::ActionContext context{};
    context.data = std::make_shared<openreport::DataSet>();

    const auto originalData = context.data;

    openreport::LoadCsvAction action{
        "data/does-not-exist.csv"
    };

    const auto result = action.execute(context);

    assert(result.status == openreport::ActionStatus::Failure);
    assert(!result.message.empty());
    assert(context.data == originalData);
}

void testLoadCsvActionHappyPath()
{
    const std::filesystem::path csvPath {
        "data/measurements.csv"
    };

    openreport::ActionContext context{};
    openreport::LoadCsvAction action{csvPath};

    const auto result = action.execute(context);

    assert(result.status == openreport::ActionStatus::Success);
    assert(context.data != nullptr);
    assert(context.data->columnCount() == 5);
    assert(context.data->rowCount() == 3);
    assert(context.data->columnNames().at(4) == "diameter");
    assert(context.data->rows().at(1).at(1) == "P10022");
}

void testBasicDataSet()
{
    const openreport::DataSet dataSet{
        {"PartId","Diameter"},
        {
            {"P-001", "10.002"},
            {"P-002", "9.998"}
        }
    };

    assert(dataSet.rowCount() == 2);
    assert(dataSet.columnCount() == 2);
    assert(!dataSet.empty());
}

void testWarningResult()
{
    const auto warning = 
        openreport::ActionResult::warning("One blank value was found.");
    assert(warning.succeeded());
}

void testNormalRectangularDataSet()
{
    const openreport::DataSet dataSet{
        {"PartId","Diameter","Length"},
        {
            {"P-001", "10.001", "25.10"},
            {"P-002", "9.998", "25.08"}
        }
    };

    assert(dataSet.rowCount() == 2);
    assert(dataSet.columnCount() == 3);
    assert(!dataSet.empty());

    for (const auto& row : dataSet.rows())
    {
        assert(row.size() == dataSet.columnCount());
    }
}

void testRowsMissingValues()
{
    const openreport::DataSet dataSet{
        {"PartId","Diameter","Length"},
        {
            {"P-001", "25.10"},
            {"P-002", "9.998", "25.08"}
        }
    };

    assert(dataSet.rowCount() == 2);
    assert(dataSet.columnCount() == 3);
    assert(!dataSet.empty());
}

void testRowsTooManyValues()
{
    const openreport::DataSet dataSet{
        {"PartId","Diameter","Length"},
        {
            {"P-001", "10.001", "25.10", "25.10", "25.10"},
            {"P-002", "9.998", "25.08"}
        }
    };

    assert(dataSet.rowCount() == 2);
    assert(dataSet.columnCount() == 3);
    assert(!dataSet.empty());
}

int main()
{
    testBasicDataSet();
    testWarningResult();
    testNormalRectangularDataSet();
    testRowsMissingValues();
    testRowsTooManyValues();

    testLoadCsvActionHappyPath();
    testLoadCsvActionMissingFile();
}