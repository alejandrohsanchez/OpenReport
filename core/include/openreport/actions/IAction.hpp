#pragma once

#include <string>

#include <openreport/actions/ActionContext.hpp>
#include <openreport/actions/ActionResult.hpp>

namespace openreport {

    class IAction
    {
        public:
            virtual ~IAction() = default;

            [[nodiscard]] virtual std::string name() const = 0;
            virtual ActionResult execute(ActionContext& context) = 0;
    };

} // namespace openreport