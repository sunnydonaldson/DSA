cc_binary(
    name = "main",
    srcs = ["main.c"],
    deps = [":avl_tree"],
)

cc_library(
    name = "avl_tree",
    srcs = ["avl_tree.c"],
    hdrs = ["avl_tree.h"],
    deps = ["//c/trees/BST:bst"],
)