# Laporan pengerjaan Eval bersama 


## Nomor 1

1. diawali dengan deklarasi stack dengan isi berupa char yang berisi command robot.
2. gunakan push untuk menaruh command terbaru di stack paling atas
3. gunakan pop untuk mendapatkan value stack teratas dan menghapusnya
4. MAIN LOGIC
    - masukkan command berupa string 
    - untuk setiap elemen di string, jika bukan B yang berarti undo, maka masukkan ke stack dengan push
    - jika berupa B maka pop atau ambil value teratas stack
    - setelah iterasi selesai, maka stack baru berisi command yang dijalankan oleh robot
    - deklarasi variabel x y untuk emnyimpan posisi robot saat ini
    - menggunakan stack yang baru, lakukan kalkulasi posisi menggunakan setiap elemen di stack.
        - jika elemen = U, maka y += 1
        - jika elemen = D, maka y -= 1
        - jika elemen = R, maka x += 1
        - jika elemen = L, maka x -= 1
    - outputkan hasil x,y



## Nomor 2
### struct
buatlah struct node dan priority queue 
dengan 
- struct node berisi prioritas, id, nama, dan timestamp.
- struct priorityQueue dengan pointer head, tail dan size dari linked list queue.

### fungsi
1. push
    - buat node baru, set id = last_id += 1, timestamp += last_timestamp += 1, nama = nama, dan ppriroty = priority.
    - jika PQ tidak ada isinya, maka set head tail menjadi node baru
    - selain itu, jika prioritas lebih kecil a.k.a lebih diprioritaskan,lakukan swap hingga prioritas sama.
    - size ++;

2. pop
    - jika PQ empty, maka tidak return apa-apa.
    - jadikan head of queue adalah next nya queue head.
    - kurangin size queue


### main
1. print deskripsi interaktif cli.
2. kalau 1, gunakan format prioritas [[spasi]] nama untuk input data
3. kalau 2, gunakan untuk ambil data teratas
4. kalau 3, gunakan untuk print semua data di priority queue (dengan while, kalau di dunia nyata, lihat queue bisa tinggal jalan menyusuri queue)
5. kalau 4, selesai programnya.



## Nomor 3

langsung kepada funsi unalive sebagai inti dari 