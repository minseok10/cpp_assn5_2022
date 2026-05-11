# Qt Minesweeper

과거 객체지향 프로그래밍 과제로 손코딩했던 C++/Qt 기반 지뢰찾기 프로그램을 현재 환경에서 다시 빌드하고 실행할 수 있도록 정리한 프로젝트입니다.

## 개발 환경

- Language: C++17
- Framework: Qt Widgets
- Primary build: qmake (`real-assn5.pro`)
- Optional build: CMake (`CMakeLists.txt`)

## 주요 기능

- Easy, Medium, Hard 난이도 선택
- 무작위 지뢰 배치
- 좌클릭으로 칸 열기
- 우클릭으로 깃발 표시 및 해제
- 빈 칸 주변 자동 열기
- 지뢰 클릭 시 패배 처리
- 모든 안전 칸을 열면 승리 처리
- Reset 버튼으로 새 게임 시작
- 플레이 시간 표시

## 빌드 및 실행

### Qt Creator 사용

1. Qt Creator에서 `real-assn5.pro` 파일을 엽니다.
2. Qt Widgets를 포함한 Qt Kit을 선택합니다.
3. Build 후 Run을 실행합니다.

### qmake 사용

```bash
qmake real-assn5.pro
make
./cpp_assn5_2022
```

Windows에서 MinGW Kit을 사용하는 경우:

```bash
qmake real-assn5.pro
mingw32-make
release\cpp_assn5_2022.exe
```

### CMake 사용

```bash
cmake -S . -B build
cmake --build build
./build/cpp_assn5_2022
```

Windows에서는 빌드 산출물 위치가 사용하는 generator와 configuration에 따라 `build/Debug` 또는 `build/Release` 아래에 생성될 수 있습니다.

## 프로젝트 구조

```text
.
├── CMakeLists.txt       # CMake 빌드 설정
├── README.md            # 프로젝트 설명
├── real-assn5.pro       # qmake 빌드 설정
├── main.cpp             # QApplication 및 MainWindow 실행 진입점
├── mainwindow.ui        # Qt Designer UI 기본 창
├── mainwindow.h/.cpp    # 난이도, 타이머, 리셋 버튼, 게임판 관리
├── pan.h/.cpp           # 지뢰찾기 게임판, 지뢰 배치, 승패 판정
├── mybutton.h/.cpp      # 각 칸 버튼, 좌/우클릭, 깃발, 열기 동작
├── timego.h/.cpp        # 플레이 시간 표시
└── 문서2.txt             # 원 과제 보고서 자료
```

## 메모

원래 과제 코드의 클래스 구조와 변수명은 최대한 유지했습니다. 현재 정리는 실행 가능성, GitHub 업로드, Qt 버전 및 플랫폼 차이로 생길 수 있는 빌드 문제를 줄이는 데 초점을 두었습니다.
