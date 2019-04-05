# SoalShift_modul3_F05
Soal Shift Sisop Modul 3

1. Membuat Faktorial

Penyelesaian :
- Pertama, deklarasikan array di global
- Pada fungsi main, menggunakan parameter argc dan argv[] untuk mendapatkan inputan
- Lalu ubah isi dari argv[] yang bertipe char menjadi integer menggunakan fungsi `atoi()` dan dimasukkan kedalam array
- Buat thread untuk dapat mensorting array tersebut
- Setelah itu, sorting array tersebut dari kecil ke besar menggunakan insertion sort
- Lalu, buat thread untuk mendapatkan faktorial dari angka yang diinputkan
- Setelah itu print, dan lakukan dengan angka yang berikutnya

2. -

3. Agmal dan Iraj

Penyelesaian :
- Deklarasikan thread dalam global, serta deklarasikan WakeUp_Status = 0 dan Spirit_Status = 100 sebagai initial state
- Lalu gunakan perintah `scanf` untuk mendapatkan input. Input 1 untuk menjalankan perintah "Agmal Ayo Bangun" dan Input 2 untuk menjalankan perintah "Iraj Ayo Bangun" yang dijalankan dalam
- Setiap perintah dijalankan, maka akan print kondisi All Status saat ini
- Dan jika ada perintah yang dijalankan sebanyak 3 kali, maka perintah yang lainnya tidak dapat dijalankan selama 10 detik dengan menggunakan fungsi `sleep(10)`
- Program akan berhenti ketika salah satu syarat terpenuhi yaitu jika WakeUp_Status >= 100 atau Spirit_Status <= 0 dengan mengeluarkan output sesuai kondisi

4. Simpan List Proses

Penyelesaian :
- Deklarasikan 3 thread dalam main
- Lalu buat 2 thread untuk menyimpan data 1 dan data 2 dari `ps -aux` dan zip data
- Setelah program akan menunggu 15 detik dengan menggunakan fungsi `sleep(15)
- Setelah itu jalankan thread ke 3 untuk meng-unzip ke 2 file tersebut

5. -
