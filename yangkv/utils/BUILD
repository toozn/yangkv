cc_library(
    name = "bloomfilter",
    srcs = ["bloomfilter.cpp"],
    hdrs = ["bloomfilter.h"],
    visibility = ["//main:__pkg__"],
)

cc_library(
    name = "hashhelper",
    srcs = ["hash_helper.cpp"],
    hdrs = ["hash_helper.h"],
    visibility = ["//main:__pkg__"],
)

cc_library(
    name = "pointcache",
    srcs = ["pointcache.cpp"],
    hdrs = ["pointcache.h"],
    visibility = ["//main:__pkg__"],
)

cc_library(
    name = "env",
    srcs = ["env.cpp"],
    hdrs = ["env.h"],
    visibility = ["//main:__pkg__"],
)

cc_library(
    name = "config",
    hdrs = ["config.h"],
    visibility = ["//main:__pkg__", "//memory:__pkg__"],
)

cc_library(
    name = "status",
    hdrs = ["status.h"],
    deps = [":env",],
    visibility = ["//main:__pkg__", "//memory:__pkg__"],
)
