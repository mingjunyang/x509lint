cmake_minimum_required(VERSION 3.16.5)
project(x509lint)

find_package(Iconv REQUIRED)
find_package(OpenSSL REQUIRED)

set(CMAKE_C_FLAGS "-g -Wall -O2 -std=c11")

if(Iconv_FOUND)
  message("Iconv FOUND")
endif()

if(OPENSSL_FOUND)
  message("OPENSSL FOUND")
endif()

include_directories(./ ${Iconv_INCLUDE_DIRS} ${OPENSSL_INCLUDE_DIR})

add_executable(${PROJECT_NAME} asn1_time.c checks.c messages.c x509lint.c)
target_link_libraries(${PROJECT_NAME} ${Iconv_LIBRARIES}
                      ${OPENSSL_CRYPTO_LIBRARY} ${OPENSSL_SSL_LIBRARY})
