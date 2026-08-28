#pragma once

#include <cstddef>
#include <string>
#include <utility>
#include <vector>

namespace openreport {

    class DataSet
    {
        public:
            using Row = std::vector<std::string>;

            DataSet() = default;

            DataSet(std::vector<std::string> columnNames, std::vector<Row> rows)
                : columnNames_(std::move(columnNames)),
                  rows_(std::move(rows))
            {
            }

            [[nodiscard]] const std::vector<std::string>& columnNames() const noexcept
            {
                return columnNames_;
            }

            [[nodiscard]] const std::vector<Row>& rows() const noexcept
            {
                return rows_;
            }

            [[nodiscard]] std::size_t columnCount() const noexcept
            {
                return columnNames_.size();
            }

            [[nodiscard]] std::size_t rowCount() const noexcept
            {
                return rows_.size();
            }

            [[nodiscard]] bool empty() const noexcept
            {
                return rows_.empty();
            }

        private:
            std::vector<std::string> columnNames_;
            std::vector<Row> rows_;
    };

} // namespace openreport