cmake_minimum_required(VERSION 3.0.0)

project(rfid)

add_executable(${PROJECT_NAME}
    ./src/main.cpp
    ./src/Golf_Membership_Manager.cpp
    ./src/app/Listener/Listener.cpp
    ./src/app/Controller/Controller.cpp
    ./src/app/Entity/MembersEntity.cpp
    ./src/app/Service/MemManageService.cpp
    ./src/hw/Rfid/mfrc522.cpp
    ./src/hw/Rfid/CardReader.cpp
    ./src/hw/Spi/SPI.cpp
    ./src/hw/Monitor/Monitor.cpp
    ./src/hw/Button/Button.cpp
    ./src/hw/Button/ManageButton.cpp
    ./src/hw/tcp_server/tcp_server.cpp
    ./src/hw/tcp_server/ComDev.cpp
    ./src/hw/LCD/LCD.cpp
    ./src/hw/I2C/I2C.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ./src
    ./src/app/Listener
    ./src/app/Controller
    ./src/app/Model
    ./src/app/Entity
    ./src/app/Service
    ./src/hw/Rfid
    ./src/hw/Spi
    ./src/hw/Monitor
    ./src/hw/Button
    ./src/hw/tcp_server
    ./src/hw/LCD
    ./src/hw/I2C
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    -lwiringPi
)

target_compile_options(${PROJECT_NAME} PUBLIC
    -Wall
)