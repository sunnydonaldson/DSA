cc_binary(
    name = "string_basics",
    srcs = ["string_basics.c"],
)

cc_binary(
    name = "main",
    srcs = ["main.c"],
    deps = [":string_operations"],
)
cc_library(
    name = "string_operations",
    srcs = ["string_operations.c"],
    hdrs = ["string_operations.h"],
)
