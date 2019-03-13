LAPORAN RESMI
SISTEM OPERASI



KELOMPOK : C1

**Oleh:**

Yuki Yanuar Ratna

05111740000023

Adnan Erlangga Raharja

05111740000100

**Asisten Pembimbing:**

M.Faris Didin Andiyar

5115100118

Departemen Infomatika

Fakultas Teknologi Informasi dan Komunikasi

Institut Teknologi Sepuluh Nopember (ITS)

Surabaya

2019

**Soal**

1. Elen mempunyai pekerjaan pada studio sebagai fotografer. Suatu hari ada seorang klien yang bernama Kusuma yang meminta untuk mengubah nama file yang memiliki ekstensi .png menjadi “[namafile]_grey.png”. Karena jumlah file yang diberikan Kusuma tidak manusiawi, maka Elen meminta bantuan kalian untuk membuat suatu program C yang dapat mengubah nama secara otomatis dan diletakkan pada direktori /home/[user]/modul2/gambar.
Catatan : Tidak boleh menggunakan crontab.

**Jawaban :**

**Cara Pengerjaan**

- Ekstrak file nature.zip

- Buatlah bash script seperti ini 
```
#!/bin/bash

angka=1 
for gambar in /home/test/nature/*.jpg 
do base64 -d "$gambar" | xxd -r > /home/test/nature/$angka.jpg 
let angka++ 
done
```
- Lalu ketik crontab -e, pada bagian paling bawah isi dengan script
```
14 14 14 2 5 /bin/bash /home/test/soal1.sh
```
- Ambil salah satu sample hari yang masuk ke dalam kriteria, lalu ubah tanggal di pc-nya

- File foto yang telah dienkripsi telah kembali 

**Kendala Yang Dialami**

-

**Screenshot**

![Screenshot1](https://2.bp.blogspot.com/-q54TWWZ6cL8/XHn0UGergHI/AAAAAAAAAlM/HZaRz7duM3I6BH3tns0sVdECK4CmzzRTgCLcBGAs/s1600/1.png)

2. Pada suatu hari Kusuma dicampakkan oleh Elen karena Elen dimenangkan oleh orang lain. Semua kenangan tentang Elen berada pada file bernama “elen.ku” pada direktori “hatiku”. Karena sedih berkepanjangan, tugas kalian sebagai teman Kusuma adalah membantunya untuk menghapus semua kenangan tentang Elen dengan membuat program C yang bisa mendeteksi owner dan group dan menghapus file “elen.ku” setiap 3 detik dengan syarat ketika owner dan grupnya menjadi “www-data”. Ternyata kamu memiliki kendala karena permission pada file “elen.ku”. Jadi, ubahlah permissionnya menjadi 777. Setelah kenangan tentang Elen terhapus, maka Kusuma bisa move on.
Catatan: Tidak boleh menggunakan crontab

**Jawaban :**

**Cara Pengerjaan**

- Buatlah bash script a, b, dan c dengan nama yang berbeda 

a. 
```
awk -F, 'NR > 1 && $7 == "2012" {arr[$1]+=$10} END {for (i in arr) {print i,arr[i]}}' WA_Sales_Products_2012-14.csv > output.sh
awk 'max < $2 { max = $1 } {min = $2} END { print max min }' output.sh
```
b. 
```
awk -F, 'NR > 1 && $7 == "2012" && $1 == "United States" {arr[$4]+=$10} END {for (i in arr) {print arr[i], i}}' WA_Sales_Products_2012-14.csv > output2.sh
sort -nrk1 output2.sh | awk '{print $2 " " $3} NR==3{exit}'
```
c.
```
awk -F, 'NR > 1 && $7 == "2012" && $1 == "United States" && $4 == "Personal Accessories" {arr[$6]+=$10} END {for (i in arr) {print arr[i],i}}' WA_Sales_Products_2012-14.csv > output3.sh
awk -F, 'NR > 1 && $7 == "2012" && $1 == "United States" && $4 == "Camping Equipment" {arr[$6]+=$10} END {for (i in arr) {print arr[i],i}}' WA_Sales_Products_2012-14.csv > output4.sh
awk -F, 'NR > 1 && $7 == "2012" && $1 == "United States" && $4 == "Outdoor Protection" {arr[$6]+=$10} END {for (i in arr) {print arr[i],i}}' WA_Sales_Products_2012-14.csv > output5.sh

echo "a. Personal Accessories"
sort -nrk1 output3.sh | awk '{print $2 " " $3 " " $4} NR==3{exit}'
echo "b. Camping Equipment"
sort -nrk1 output4.sh | awk '{print $2 " " $3 " " $4} NR==3{exit}'
echo "c. Outdoor Protection"
sort -nrk1 output5.sh | awk '{print $2 " " $3 " " $4} NR==3{exit}'
```
- Ketika di bash maka akan muncul hasil yang diinginkan oleh soal

**Kendala Yang Dialami**

-

**Screenshot**

2.a.

- Isi output.sh

![Screenshot2a1](https://4.bp.blogspot.com/-RFCmspP7Vzc/XHn0RzVtaDI/AAAAAAAAAlI/W0J3f9TwJt8y_giSVxeRmOxvi795PsxQgCLcBGAs/s1600/2a1.png)

- Hasil ketika di bash

![Screenshot2a2](https://4.bp.blogspot.com/-pBFDpGCytB4/XHn0RpWU8NI/AAAAAAAAAlE/SWjPsTmlCVUBiSEW5WHU0Ek_Dff4IhSDQCLcBGAs/s1600/2a2.png)

2.b.

- Isi dari output2.sh

![Screenshot2b1](https://4.bp.blogspot.com/-_ZWuOt3FEGo/XHn0UlYaF7I/AAAAAAAAAlU/qM-GFEVut4U7rH0vvzO_hCnScp-SoaJBwCLcBGAs/s1600/2b1.png)

- Hasil ketika di bash

![Screenshot2b2](https://2.bp.blogspot.com/-wRChmwM8mWA/XHn0UuivpRI/AAAAAAAAAlQ/MWplqhNfybUy4dmfdHQJL6nnv2cdhPeewCLcBGAs/s1600/2b2.png)

2.c.

- Isi dari output3.sh

![Screenshot2c1](https://1.bp.blogspot.com/-dj5IN3b99-c/XHn0VfohqrI/AAAAAAAAAlY/ux79BPc3u642wLV1Lzqi8QZ0rAwAIiogwCLcBGAs/s1600/2c1.png)

- Isi dari output4.sh

![Screenshot2c2](https://4.bp.blogspot.com/-mNvBQguXIAw/XHn0WkuW33I/AAAAAAAAAlc/Vfu1cbLL_XUDVVU13c06cCnylrhfbbaywCLcBGAs/s1600/2c2.png)

- Isi dari output5.sh

![Screenshot2c3](https://3.bp.blogspot.com/-oQ8WVEleIGo/XHn0WpGVGkI/AAAAAAAAAlg/6Rr9AWN2AEY9UZDb2UsnV2WtFA1va07vQCLcBGAs/s1600/2c3.png)

- Hasil ketika di bash
 
![Screenshot2c4](https://3.bp.blogspot.com/-j9BDuOy8lGE/XHn0YETe5SI/AAAAAAAAAlk/4BB0-hNCwZQjDwjEMdo6CMH3VuJ4tT49gCLcBGAs/s1600/2c4.png)

3. Diberikan file campur2.zip. Di dalam file tersebut terdapat folder “campur2”. 
Buatlah program C yang dapat :
i)  mengekstrak file zip tersebut.
ii) menyimpan daftar file dari folder “campur2” yang memiliki ekstensi .txt ke dalam file daftar.txt. 
Catatan:  
        ◦ Gunakan fork dan exec.
        ◦ Gunakan minimal 3 proses yang diakhiri dengan exec.
        ◦ Gunakan pipe
        ◦ Pastikan file daftar.txt dapat diakses dari text editor
        
**Jawaban :**

**Cara Pengerjaan**

- Buat bash scriptnya terlebih dahulu
```
#!/bin/bash

length=12
digits=({0..9})
lower=({a..z})
upper=({A..Z})
CharArray=(${digits[*]} ${lower[*]} ${upper[*]})
ArrayLength=${#CharArray[*]}
password=""
for i in `seq 1 $length`
do        
	index=$(($RANDOM%$ArrayLength))    
	char=${CharArray[$index]}        
	password=${password}${char}
done 

file=password
numb=1

while test -e "$file$numb.txt"; do        
	(( ++numb ))
done

fname="$file$numb.txt"

echo $password > "$fname"
```
- Ketika di bash pertama kali seharusnya outputnya disimpan di password1.txt. Dapat dicek dengan perintah `ls`

- Jika ada file password1.txt, coba lihat isinya dengan perintah `cat password1.txt`

- Ketika di bash selanjutnya outputnya akan disimpan di password2.txt, password3.txt, dan seterusnya. Untuk tiap-tiap file akan berisi password yang berbeda

**Kendala Yang Dialami**

Bingung bagaimana caranya jika sudah membuat sampai password5.txt ketika password2.txt dihapus maka selanjutnya ketika di bash disimpan di password6.txt bukan password2.txt

**Screenshot**

-Melakukan bash pertama yang menghasilkan password1.txt

![Screenshot3a1](https://2.bp.blogspot.com/-5zfwM0Pad9M/XHn0YkCm6OI/AAAAAAAAAls/TEntx4rkCPkVT9kiAQWigZ1vtjeQfK72wCLcBGAs/s1600/31.png)

![Screenshot3a2](https://4.bp.blogspot.com/-wTCv2wtyLOE/XHn0YYjayKI/AAAAAAAAAlo/JrU6EJXvHqsWP53M48B4wJlruPEO-xgDgCLcBGAs/s1600/32.png)

-Melakukan bash kedua yang menghasilkan password2.txt

![Screenshot3b1](https://3.bp.blogspot.com/-aA_vv_3gRMY/XHn0aeJM4lI/AAAAAAAAAlw/7CbHLn1F2AAVnk_DaTzsetB8wkcWoT3jQCLcBGAs/s1600/33.png)

![Screenshot3b2](https://3.bp.blogspot.com/-fztSe_DJHa8/XHn0cDrSCXI/AAAAAAAAAl4/VIhJIqubBeY19mkW0u6NGPryLx6GcZ60QCLcBGAs/s1600/34.png)

4.  Dalam direktori /home/[user]/Documents/makanan terdapat file makan_enak.txt yang berisikan daftar makanan terkenal di Surabaya. Elen sedang melakukan diet dan seringkali tergiur untuk membaca isi makan_enak.txt karena ngidam makanan enak. Sebagai teman yang baik, Anda membantu Elen dengan membuat program C yang berjalan setiap 5 detik untuk memeriksa apakah file makan_enak.txt pernah dibuka setidaknya 30 detik yang lalu (rentang 0 - 30 detik).
Jika file itu pernah dibuka, program Anda akan membuat 1 file makan_sehat#.txt di direktori /home/[user]/Documents/makanan dengan '#' berisi bilangan bulat dari 1 sampai tak hingga untuk mengingatkan Elen agar berdiet.

Contoh:
File makan_enak.txt terakhir dibuka pada detik ke-1
Pada detik ke-10 terdapat file makan_sehat1.txt dan makan_sehat2.txt

Catatan: 
    • dilarang menggunakan crontab
    • Contoh nama file : makan_sehat1.txt, makan_sehat2.txt, dst

**Jawaban :**

**Cara Pengerjaan**

- Buat bash script untuk enkripsinya terlebih dahulu
```
#!/bin/bash

today="$( date +"%H:%M %d-%m-%Y" )"
jam="$( date +"%H" )"

alpha=({a..z})
encrypt=( "${alpha[@]:(-(26-$jam))}" )
encrypt+=( "${alpha[@]:0:$jam}" )

alpha1=({A..Z})
encrypt1=( "${alpha1[@]:(-(26-$jam))}" )
encrypt1+=( "${alpha1[@]:0:$jam}" )

awk '{print}' /var/log/syslog | tr "${alpha[*]}" "${encrypt[*]}"| tr "${alpha1[*]}" "${encrypt1[*]}"  > "$today".log
```
- Lalu buka crontab -e, pada bagian bawah sendiri isi dengan
```
*/60 * * * * /bin/bash /home/test/soal4.sh
```
- Maka setiap satu jam, bash script akan menghasilkan output yang disimpan di file log dengan pola filename “jam:menit tanggal-bulan-tahun” sekarang 

- Lalu buat bash script untuk dekripsinya

- Ketika di bash maka file yang sebelumnya di enkripsi dapat kembali seperti semula

- Setelah itu buat bash script untuk dekripsinya 
```
#!/bin/bash

hurufkecil=(a b c d e f g h i j k l m n o p q r s t u v w x y z)
hurufbesar=(A B C D E F G H I J K L M N O P Q R S T U V W X Y Z)

echo “Enter the filename :”
read hour
jam=${hour:0:2}

bawah=${hurufkecil[$jam]}
atas=${hurufbesar[$jam]}

cat “$hour” | tr “[$bawah-za-$bawah]” ‘[a-z]’ | tr “[$atas-ZA-$atas]” ‘[A-Z]’ > “$hour”.decrypt
```
- Ketika di bash, maka Anda harus memasukkan nama file yang didekripsi

- Lalu coba buka nama file yang Anda dekripsi dengan penambahan “.decrypt” di belakangnya maka akan muncul kembali record syslog yang sebelumnya dienkripsi

**Kendala Yang Dialami**

Salah membaca soal yang 4e, dikira deskripsi bukan dekripsi

**Screenshot**

-Enkripsi

![Screenshot4a1](https://3.bp.blogspot.com/-9NpoA-t2MYg/XHn0cLFXrKI/AAAAAAAAAl0/BdC1IYprWgQ9jaHp7BkU70T0eoGCFsFjwCLcBGAs/s1600/41.png)

![Screenshot4a2](https://4.bp.blogspot.com/-ZT5_QOtN55g/XHn0dUlrTtI/AAAAAAAAAl8/FwZtyEODSbQCpy0pR0UWAnHJ9VDaQQpJgCLcBGAs/s1600/42.png)

-Dekripsi

![Screenshot4b1](https://1.bp.blogspot.com/-4-TzJSAc2kg/XHn0f1h9V1I/AAAAAAAAAmE/jGKaWex11EwlYq1T7T8CFa491x_6AIeGgCLcBGAs/s1600/4b1.png)

![Screenshot4b2](https://1.bp.blogspot.com/-kmzcnx1MEzM/XHn0fPk2uXI/AAAAAAAAAmA/muEUXEXqalYB_pYPQnbxDDo8MyBZLtaBgCLcBGAs/s1600/4b2.png)

5. Kerjakan poin a dan b di bawah:
    a. Buatlah program c untuk mencatat log setiap menit dari file log pada syslog ke /home/[user]/log/[dd:MM:yyyy-hh:mm]/log#.log
Ket:
    • Per 30 menit membuat folder /[dd:MM:yyyy-hh:mm]
    • Per menit memasukkan log#.log ke dalam folder tersebut
      ‘#’ : increment per menit. Mulai dari 1
    b. Buatlah program c untuk menghentikan program di atas.
NB: Dilarang menggunakan crontab dan tidak memakai argumen ketika menjalankan program.

**Jawaban :**

**Cara Pengerjaan**

- Buat bash script seperti berikut
```
#!/bin/bash

awk '/cron/ || /CRON/,!/sudo/' /var/log/syslog | awk 'NF < 13 {print}' >> /home/test/modul1/logsoal5.log
```
- Lalu buka crontab -e, pada bagian paling bawah sendiri isi dengan script
```
2-30/6 * * * * /bin/bash /home/test/soal5.sh
```
- Ambil salah satu sample, misal pukul 13.02. Maka pada direktori modul1 akan terdapat file logsoal5.log dengan isi record syslog yang sesuai ketentuan soal

**Kendala Yang Dialami**

-

**Screenshot**

![Screenshot5](https://4.bp.blogspot.com/-3wi9LZ7uXY4/XHn0gaIhI9I/AAAAAAAAAmI/RDok2Fu4WH0EP21d6BrJ7HOt8bKjkUzEwCLcBGAs/s1600/5.png)
