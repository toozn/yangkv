cc_library(
    name = "singleton",
    srcs = ["singleton.h"],
    deps = [":yangkvMain"]
)

cc_library(
    name = "yangkvMain",
    srcs = ["yangkvMain.cpp"],
    hdrs = ["yangkvMain.h"],
    deps = ["//memory:skip_list", "//utils:env"],
)

cc_binary(
	name = "test",
	srcs = ["test.cpp"],
	deps = [":singleton"],
)
