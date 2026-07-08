# DumbPhysicsEngine

## 필요 항목

- CMake
- C++ 워크로드가 포함된 Visual Studio 2022 Community
- 전역 환경변수 `VCPKG_ROOT`에 등록된 vcpkg
- 이 프로젝트에서 사용하는 패키지
  - `glm`
  - `glfw`
  - `glad`

## vcpkg 설치

`VCPKG_ROOT`가 아직 설정되어 있지 않다면, 먼저 원하는 위치에 vcpkg를 설치한 뒤 환경변수를 등록하세요.

```powershell
git clone https://github.com/microsoft/vcpkg.git D:\vcpkg
cd D:\vcpkg
.\bootstrap-vcpkg.bat
```

예를 들어 `D:\vcpkg`에 설치했다면, `VCPKG_ROOT` 값을 `D:\vcpkg`로 설정하면 됩니다.

## vcpkg 업데이트

`VCPKG_ROOT`가 이미 등록되어 있다면, 아래 명령으로 vcpkg 자체를 업데이트하세요.

```powershell
cd $env:VCPKG_ROOT
git pull
.\bootstrap-vcpkg.bat
```

## 클론 후 설정

이 저장소를 클론한 뒤에는, 이미 고정된 vcpkg 경로를 가리키도록 설정된 preset으로 구성하면 됩니다.

```powershell
cmake --preset vcpkg
cmake --build build
```

이전에 이미 한 번 구성한 적이 있다면, 위 명령을 실행하기 전에 `build` 디렉터리 또는 최소한 `build/CMakeCache.txt`를 한 번 삭제하세요.

Visual Studio나 VS Code를 사용할 경우에도 동일한 고정 경로를 사용합니다.

- `$env{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake`

vcpkg를 다른 위치로 옮겼다면 `VCPKG_ROOT` 환경변수만 다시 설정하면 됩니다.

- [CMakePresets.json](CMakePresets.json)
- [.vscode/settings.json](.vscode/settings.json)

## 프로젝트 설명

이 프로젝트는 기본 물리 시뮬레이션을 구현하는 간단한 물리 엔진 프로토타입입니다.
