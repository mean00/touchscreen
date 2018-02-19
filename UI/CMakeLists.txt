PROJECT(UI C CXX )
ADD_EXECUTABLE(ui_test main.cpp)
include_directories(/usr/local/include/ucglib)
link_directories(/usr/local/lib)
TARGET_LINK_LIBRARIES(ui_test 
        ucgsdl 
        ucgbase 
        SDL
)
