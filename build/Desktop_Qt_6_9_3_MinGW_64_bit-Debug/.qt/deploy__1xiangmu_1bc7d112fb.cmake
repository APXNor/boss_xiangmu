include("D:/1xiangmu/build/Desktop_Qt_6_9_3_MinGW_64_bit-Debug/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/1xiangmu-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase;qtdeclarative;qtdeclarative;qtdeclarative;qtmultimedia;qtmultimedia")

qt6_deploy_runtime_dependencies(
    EXECUTABLE "D:/1xiangmu/build/Desktop_Qt_6_9_3_MinGW_64_bit-Debug/1xiangmu.exe"
    GENERATE_QT_CONF
)
