#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

// ZAAFİYET BURADA!
// Gelen veriyi boyunu kontrol etmeden kopyalayan fonksiyon.
void vulnerable_function(char *input) {
    char buffer[64]; // Sadece 64 byte yer var
    
    // strcpy sınır kontrolü yapmaz! 
    // Eğer input 64'ten büyükse, bellekteki diğer verileri ezer.
    strcpy(buffer, input); 
    
    printf("[+] Veri alındı: %s\n", buffer);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Socket oluşturma
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Port ayarları (Port 9999)
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(9999);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    printf("💀 Vulnerable Server 9999 portunda dinliyor...\n");
    printf("⚠️  UYARI: Bu program Buffer Overflow'a açıktır!\n");

    while(1) {
        printf("\n[Target] Bağlantı bekleniyor...\n");
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept");
            exit(EXIT_FAILURE);
        }

        // Veriyi oku
        read(new_socket, buffer, 1024);
        
        // Zaafiyetli fonksiyona gönder
        vulnerable_function(buffer);
        
        close(new_socket);
        // Buffer'ı temizle
        memset(buffer, 0, 1024);
    }
    return 0;
}
