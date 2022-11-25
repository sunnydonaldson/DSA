cc_library(
  name = "array_adt",
  srcs = [
    "arrayADT.c",
    "set_operations.c",
    "insert.c",
    "searching.c",
    "sorting.c",
    "array_helpers.c",
  ],
  hdrs = [
    "arrayADT.h",
  ],
)

cc_binary(
  name = "main",
  srcs = ["main.c"],
  deps = [
    ":array_adt",
  ],
)
