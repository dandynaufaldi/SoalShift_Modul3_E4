# SoalShift_Modul3_E4
Sistem Operasi Soal Shift Modul 3

----------------------------------------------------------
SOAL 1

- Asumsi hanya 1 Source Code
- Asumsi user memilih mode penggunaan
- Weapon menyimpan jumlah senjata setiap tipe
- Asumsi 1 terminal 1 mode penggunaan

----------------------------------------------------------
SOAL 3

- lohan, kepiting adalah variabel status binatang
- Asumsi boleh memberi interface menu dan keterangan
- pthread_cancel untuk mengakhiri permainan

----------------------------------------------------------
SOAL 4

- Asumsi input paramater langsung masuk ke argument pada fungsi main.
- int argc menyimpan banyaknya argument yang dipassing
- char \*argv[] menyimpan argument dalam bentuk string
- Karena argumen diterima sebagai string, dipakai fungsi atoi() dari stdlib untuk mengubah ke integer
- Untuk fungsi faktorial agar bisa menampung nilai yang besar digunakan tipe Long double

----------------------------------------------------------
SOAL 5
- Asumsi input paramater langsung masuk ke argument pada fungsi main.
- int argc menyimpan banyaknya argument yang dipassing
- char \*argv[] menyimpan argument dalam bentuk string
- pencarian nama dilakukan melalui fungsi grep dengan argumen -c yang mangembalikan banyaknya kemunculan string pattern
- untuk passing variabel nama ke dalam fungsi grep dalam system call, dibuat dulu string command dengan sprintf
