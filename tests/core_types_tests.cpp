#include <cassert>

#include <openreport/actions/ActionResult.hpp>
#include <openreport/dataset/DataSet.hpp>

int main()
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

    const auto warning = 
        openreport::ActionResult::warning("One blank value was found.");

    assert(warning.succeeded());
}