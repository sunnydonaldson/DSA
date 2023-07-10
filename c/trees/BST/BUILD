cc_binary(
    name = "main",
    srcs = ["main.c"],
    deps = [":bst"],
)

cc_library(
    name = "bst",
    srcs = ["BST.c"],
    hdrs = ["BST.h"],
    visibility = ["//c/trees/BST:__subpackages__"],
)
