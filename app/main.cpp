#include <iostream>

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

    std::cout << "OpenReport\n";
    std::cout << "Rows: " << dataSet.rowCount() << "\n";
    std::cout << "Columns: " << dataSet.columnCount() << '\n';
}