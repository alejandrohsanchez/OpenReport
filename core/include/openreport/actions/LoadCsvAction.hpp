#pragma once

#include <filesystem>
#include <string>

#include <openreport/actions/IAction.hpp>

namespace openreport {
    
class LoadCsvAction final : public IAction
{
public:
    explicit LoadCsvAction(std::filesystem::path csvPath);

    [[nodiscard]] std::string name() const override;
    ActionResult execute(ActionContext& context) override;

private:
    std::filesystem::path csvPath_;
};

} // namespace openreport