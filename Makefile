all:
	# -fno-stack-protector: Kanarya korumasını kapatır (Bellek taşmasına izin verir)
	# -z execstack: Stack üzerinde kod çalıştırılmasına izin verir
	# -m32: 32-bit olarak derle (Exploit mantığını anlamak daha kolaydır)
	# NOT: 32-bit kütüphaneler yoksa hata verebilir, o zaman -m32'yi silip 64-bit devam et.
	gcc vuln_server.c -o vuln_server -fno-stack-protector -z execstack -no-pie

clean:
	rm -f vuln_server
