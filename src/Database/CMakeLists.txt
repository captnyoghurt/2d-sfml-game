# Database sources
## jsoncpp headers

set(Database_Jsoncpp_Srcs
    ${Srcdir}/Database/json/allocator.h
    ${Srcdir}/Database/json/assertions.h
    ${Srcdir}/Database/json/autolink.h
    ${Srcdir}/Database/json/config.h
    ${Srcdir}/Database/json/features.h
    ${Srcdir}/Database/json/forwards.h
    ${Srcdir}/Database/json/json.h
    ${Srcdir}/Database/json/reader.h
    ${Srcdir}/Database/json/value.h
    ${Srcdir}/Database/json/version.h
    ${Srcdir}/Database/json/writer.h
    ${Srcdir}/Database/json_reader.cpp
    ${Srcdir}/Database/json_tool.h
    ${Srcdir}/Database/json_value.cpp
    ${Srcdir}/Database/json_valueiterator.inl
    ${Srcdir}/Database/json_writer.cpp
)


set(Database_Srcs
    ${Database_Jsoncpp_Srcs}
    ${Srcdir}/Database/DatabaseJson.cpp
    ${Srcdir}/Database/DatabaseJson.h
    PARENT_SCOPE
)