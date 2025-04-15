# propota de organização :

cg-football-opengl/
├── include/                  # Headers (.h)
│   ├── draw.h               # Funções de desenho (campo, linhas, círculo, etc.)
│   ├── ball.h               # Estrutura e lógica da bola
│   ├── score.h              # Controle do placar
│   ├── players.h            # Representação dos jogadores
│   └── input.h              # Manipulação de teclado
│
├── src/                      # Implementações (.c)
│   ├── main.c               # Inicialização OpenGL e loop principal
│   ├── draw.c               # Implementação dos desenhos com Bresenham
│   ├── ball.c               # Lógica de movimento da bola
│   ├── score.c              # Atualização do placar
│   ├── players.c            # Desenho e lógica dos jogadores
│   └── input.c              # Controle de entrada via teclado
│
├── assets/                  # Modelos externos (se usar Blender, por exemplo)
│   └── players.obj
│
├── build/                   # Arquivos de saída (compilação)
│
├── Makefile                 # Compilação do projeto
└── README.md                # Descrição do projeto

# 🔧 Requisitos

Para compilar e rodar o GoalGL, você precisa das seguintes dependências:

### 🎯 Dependências

- **GCC / Clang** (compilador C)
- **Make**
- **OpenGL** (GL, GLU)
- **GLUT** (`freeglut`)
- **FFmpeg** (`ffplay` ou `mpg123` para música)
- **Imagemagick** (opcional, para edição de PNG)
- **STB Image** (já incluso no projeto)

### 🐧 Instalação em distribuições Linux

#### Manjaro / Arch:

```bash
sudo pacman -S base-devel gcc make freeglut glew ffmpeg mpg123 imagemagick

```

#### Ubuntu / Debian:

```bash
sudo apt update
sudo apt install build-essential libgl1-mesa-dev freeglut3-dev libglew-dev \
             ffmpeg mpg123 imagemagick
