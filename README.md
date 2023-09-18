<img align="right" width="96px" src="./assets/1200px_cpp_logo.svg.png">

# rapidjson-utility

[![Clang Format](https://github.com/Dup4/rapidjson-utility/workflows/Clang%20Format/badge.svg)](https://github.com/Dup4/rapidjson-utility/actions/workflows/clang_format.yml)
[![Test](https://github.com/Dup4/rapidjson-utility/workflows/Test/badge.svg)](https://github.com/Dup4/rapidjson-utility/actions/workflows/test.yml)
[![codecov](https://codecov.io/gh/Dup4/rapidjson-utility/branch/main/graph/badge.svg)](https://codecov.io/gh/Dup4/rapidjson-utility)
[![GitHub release](https://img.shields.io/github/release/Dup4/rapidjson-utility.svg)](https://GitHub.com/Dup4/rapidjson-utility/releases/)

## Integration

### CMake

```cmake
FetchContent_Declare(
    rapidjson-utility
    QUIET
    GIT_REPOSITORY https://github.com/Dup4/rapidjson-utility.git
    GIT_TAG v{x.y.z} # Where `x.y.z` is the release version you want to use.
)
```

### Bazel

```bazel
git_repository(
    name = "rapidjson-utility",
    remote = "https://github.com/Dup4/rapidjson-utility.git",
    tag = "v{x.y.z}",  # Where `x.y.z` is the release version you want to use.
)
```

## Usage

See the usage in the [unit test](./test/rapidjson_utility_usage_test.cc)

## License

[MIT](./LICENSE) License © 2022 - PRESENT [Dup4][dup4]

[dup4]: https://github.com/Dup4
