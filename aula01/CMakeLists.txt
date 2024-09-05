

cmake_minimum_required(VERSION 3.8)
project(my_project C)

# Ativa a exportação do arquivo compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Defina o diretório onde estão os arquivos-fonte
set(SOURCE_DIR "C:/Users/anton/OneDrive/Área de Trabalho/ESTRUTURA DE DADOS/aula01")

# Garante que os arquivos-fonte sejam encontrados
file(GLOB_RECURSE SOURCES
    "${SOURCE_DIR}/*.c"
)

# Cria o executável
add_executable(my_app ${SOURCES})

# Se você precisar de qualquer definição de pré-processador, adicione aqui
# add_definitions(-DSOME_DEFINITION)

# Se você precisar adicionar diretórios de cabeçalhos, faça isso aqui
# target_include_directories(my_app PUBLIC "${INCLUDE_DIR}")

# Se estiver usando cabeçalhos pré-compilados, adicione-os assim
# target_precompiled_headers(my_app PRIVATE "${SOURCE_DIR}/pch.h")

