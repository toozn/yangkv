cc_library(
    name = "singleton",
    srcs = ["singleton.cpp"],
    hdrs = ["singleton.h"],
    visibility = ["//__pkg__"],
    deps = [":yangkvMain"]
)

cc_library(
    name = "yangkvMain",
    srcs = ["yangkvMain.cpp"],
    hdrs = ["yangkvMain.h"],
    deps = ["//memory:skip_list", "//utils:env"],
    visibility = ["//__pkg__"],
)

cc_binary(
	name = "test",
	srcs = ["test.cpp"],
	deps = [":singleton"],
    visibility = ["//__pkg__"],
)
