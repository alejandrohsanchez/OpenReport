#pragma once

#include <string>
#include <utility>

namespace openreport {

    enum class ActionStatus
    {
        Success,
        Warning,
        Failure
    };

    struct ActionResult
    {
        ActionStatus status{ActionStatus::Success};
        std::string message;

        [[nodiscard]] bool succeeded() const noexcept
        {
            return status != ActionStatus::Failure;
        }

        static ActionResult success(std::string message = {})
        {
            return {ActionStatus::Success, std::move(message)};
        }

        static ActionResult warning(std::string message)
        {
            return {ActionStatus::Warning, std::move(message)};
        }

        static ActionResult failure(std::string message)
        {
            return {ActionStatus::Failure, std::move(message)};
        }
    };
} // namespace openreport