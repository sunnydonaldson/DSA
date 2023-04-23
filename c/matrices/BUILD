cc_library(
  name = "diagonal_matrix",
  srcs = ["diagonal_matrix.c"],
  hdrs = ["diagonal_matrix.h"],
)

cc_library(
  name = "triangular_matrices",
  srcs = ["triangular_matrices.c"],
  hdrs = ["triangular_matrices.h"],
)

cc_library(
  name = "symmetric_matrix",
  srcs = ["symmetric_matrix.c"],
  hdrs = ["symmetric_matrix.h"],
  deps = [":triangular_matrices"],
)

cc_binary(
  name = "matrices",
  srcs = ["main.c"],
  deps = [
  ":diagonal_matrix",
  ":triangular_matrices",
  ":symmetric_matrix",
  ],
)
