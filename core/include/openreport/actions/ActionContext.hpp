#pragma once

#include <memory>

namespace openreport {

    class DataSet;
    class ProjectConfig;
    class AnalysisResults;
    class ReportAssets;


    struct ActionContext
    {
        std::shared_ptr<DataSet> data;
        std::shared_ptr<ProjectConfig> config;
        std::shared_ptr<AnalysisResults> results;
        std::shared_ptr<ReportAssets> assets;
    };

} // namespace openreport