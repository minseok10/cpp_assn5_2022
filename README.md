# Qt Minesweeper Original

이 브랜치는 2022년에 객체지향 프로그래밍 과제로 직접 손코딩했던 C++/Qt 지뢰찾기 프로그램의 원본을 기념하고 보존하기 위한 브랜치입니다.

`main` 브랜치에는 현재 환경에서 더 쉽게 빌드하고 배포할 수 있도록 정리한 버전이 있지만, 이 `original` 브랜치에서는 당시 작성했던 코드의 구조와 스타일을 최대한 그대로 남기는 것을 목표로 합니다.

## 프로젝트 소개

- C++와 Qt Widgets로 만든 GUI 지뢰찾기 프로그램입니다.
- `QMainWindow`, `QWidget`, `QPushButton`, `QTimer`, `QElapsedTimer` 등을 사용합니다.
- 난이도 선택, 지뢰 배치, 칸 열기, 깃발 표시, 승리/패배 판정, 리셋 기능을 포함합니다.

## 개발 당시 정보

- 작성 시기: 2022년
- 목적: 객체지향 프로그래밍 과제
- 언어: C++17
- GUI 프레임워크: Qt Widgets
- 원래 빌드 방식: qmake (`real-assn5.pro`)
- 추가 빌드 방식: CMake (`CMakeLists.txt`)

## 주요 파일

```text
.
├── real-assn5.pro       # qmake 프로젝트 파일
├── CMakeLists.txt       # 현재 환경에서 빌드하기 위해 추가한 CMake 설정
├── main.cpp             # QApplication 및 MainWindow 실행 진입점
├── mainwindow.ui        # Qt Designer UI 파일
├── mainwindow.h/.cpp    # 메인 창, 난이도 선택, 타이머, 리셋, 게임판 관리
├── pan.h/.cpp           # 게임판, 지뢰 배치, 주변 지뢰 수 계산, 승패 판정
├── mybutton.h/.cpp      # 지뢰찾기 칸 버튼, 좌클릭/우클릭 처리
├── timego.h/.cpp        # 플레이 시간 표시
└── 문서2.txt             # 당시 과제 보고서 자료
```

## qmake 빌드 방법

Qt가 설치되어 있고 `qmake`가 PATH에 잡혀 있다면 다음처럼 빌드할 수 있습니다.

```bash
qmake real-assn5.pro
make
```

macOS에서 Homebrew Qt를 사용하는 경우:

```bash
/opt/homebrew/opt/qt/bin/qmake real-assn5.pro
make
```

Windows에서 Qt MinGW Kit을 사용하는 경우:

```bat
qmake real-assn5.pro
mingw32-make
```

## CMake 빌드 방법

원본 코드는 그대로 두고, 현재 개발 환경에서 더 쉽게 빌드할 수 있도록 `CMakeLists.txt`를 추가했습니다.

macOS 또는 Linux:

```bash
cmake -S . -B build
cmake --build build
```

macOS에서 앱 번들로 실행하는 경우:

```bash
open build/cpp_assn5_2022_original.app
```

Windows:

```bat
cmake -S . -B build
cmake --build build --config Release
```

Windows에서 생성되는 실행 파일 위치는 사용하는 generator와 Qt Kit에 따라 `build\Release` 또는 `build\Debug` 아래가 될 수 있습니다.

## 빌드 확인

이 브랜치에서는 코드 파일을 수정하지 않고, 문서와 CMake 설정만 추가했습니다. macOS Homebrew Qt 6 환경에서 다음 빌드를 확인했습니다.

- qmake shadow build 성공
- CMake shadow build 성공

## 메모

이 브랜치의 코드는 과제 제출 당시의 손코딩 느낌을 남기기 위한 원본입니다. 따라서 현대적인 정리, 스타일 수정, 버그 수정은 가능하면 `main` 브랜치에서 확인하는 것이 좋습니다.
