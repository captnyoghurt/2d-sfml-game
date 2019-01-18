# Jsoncpp

set(Jsoncpp_Srcs
    ${Srcdir}/third_party/jsoncpp/dist/json/json-forwards.h
    ${Srcdir}/third_party/jsoncpp/dist/json/json.h
    ${Srcdir}/third_party/jsoncpp/dist/jsoncpp.cpp
)

# Create the jsoncpp sources
execute_process(
    COMMAND python amalgamate.py
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/jsoncpp/
)


set(Third_Party_Srcs
    ${Jsoncpp_Srcs}
    PARENT_SCOPE
)