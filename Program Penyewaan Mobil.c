// Library
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

// Data Structure
typedef struct data
{
    char nama[1000], status[1000], lokasi[1000],kota[100],kapasitas[1000],usernames[1000];
    int id,counter,tahun,harga,total,durasi,date,month,year;

    struct data *next; // linked list
    struct data *left,*right; // Tree sorting
} data;


//data global mobil
data mobil[100];
data tempmobil[100];


//Cari Nama
int sequentialSearchNama(char *nama, int n){
    int i;
    for(i = 1; i <= n; i++){
        if(strcmpi(nama, mobil[i].nama) == 0){
            return i;
        }
    }
    return -1;
}

//Cari ID
int sequentialSearchID(int id, int n){
    int i;
    for(i = 0; i < n; i++){
        if(id == mobil[i].id){
            return i;
        }
    }
    return -1;
}

//cari status
void sequentialSearchStatus(char *status, int n,int *jumlah){
    int i;
    *jumlah = 0;
    for(i = 1; i <= n; i++){
        if(strcmpi(status, mobil[i].status) == 0){
            printf("\n");
            printf("ID          : %d\n", mobil[i].id);
            printf("Nama        : %s\n", mobil[i].nama);
            printf("Status      : %s\n", mobil[i].status);
            printf("Lokasi      : %s\n", mobil[i].lokasi);
            printf("Kota        : %s\n", mobil[i].kota);
            printf("Tahun       : %d\n", mobil[i].tahun);
            printf("Kapasitas   : %s\n", mobil[i].kapasitas);
            printf("Harga       : Rp %d,-\n", mobil[i].harga);

            printf("\n");
            garis();
            (*jumlah)++;
        }
    }

}

//cari harga
void sequentialSearchHarga(int harga, int n,int *jumlah){
    int i;
    *jumlah = 0;
    for(i = 1; i < n; i++){
        if(harga>= mobil[i].harga){
            printf("\n");
            printf("ID          : %d\n", mobil[i].id);
            printf("Nama        : %s\n", mobil[i].nama);
            printf("Status      : %s\n", mobil[i].status);
            printf("Lokasi      : %s\n", mobil[i].lokasi);
            printf("Kota        : %s\n", mobil[i].kota);
            printf("Tahun       : %d\n", mobil[i].tahun);
            printf("Kapasitas   : %s\n", mobil[i].kapasitas);
            printf("Harga       : Rp %d,-\n", mobil[i].harga);
            printf("\n");
            garis();
            (*jumlah)++;
        }
    }

}

//cari tahun
void sequentialSearchtahun(int tahun, int n,int *jumlah){
    int i;
    *jumlah = 0;
    for(i = 1; i <= n; i++){
        if(tahun<= mobil[i].tahun){
            printf("\n");
            printf("ID          : %d\n", mobil[i].id);
            printf("Nama        : %s\n", mobil[i].nama);
            printf("Status      : %s\n", mobil[i].status);
            printf("Lokasi      : %s\n", mobil[i].lokasi);
            printf("Kota        : %s\n", mobil[i].kota);
            printf("Tahun       : %d\n", mobil[i].tahun);
            printf("Kapasitas   : %s\n", mobil[i].kapasitas);
            printf("Harga       : Rp %d,-\n", mobil[i].harga);
            printf("\n");
            garis();
            (*jumlah)++;
        }
    }

}


//Sorting dengan Tree Inorder
void printListInorder(data *now){
  if(now!=NULL){
    printListInorder(now->left);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("%c %03d\t\t\t\t\t        %c\n%c %-42s    %c\n%c %-6s\t\t\t\t        %c\n%c %-42s    %c\n",186, now->id,186,186,now->nama,186,186, now->status,186,186, now->lokasi,186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    printListInorder(now->right);
  }
}

// menambahkan node baru dengan menggunakan memori alokasi
struct data *newNode(int id,int tahun,int harga,char *nama,char *status,char *lokasi,char *kota,char *kapasitas){
    data *temp = (data *) malloc (sizeof(data));
    temp->id = id;

    temp->tahun = tahun;
    temp->harga = harga;
    strcpy(temp->nama, nama);
    strcpy(temp->status, status);
    strcpy(temp->lokasi, lokasi);
    strcpy(temp->kota, kota);
    strcpy(temp->kapasitas, kapasitas);

    temp->left=temp->right=NULL;
    return temp;
}

// masukkan data yang diurutkan secara id ke tree untuk semua wilayah
data *insertToTreeSortID(data *node,int id,int tahun,int harga,char *nama,char *status,char *lokasi,char *kota,char *kapasitas){
  if(node==NULL) return newNode(id,tahun,harga,nama,status,lokasi,kota,kapasitas);

  if (id < node->id){
    node->left = insertToTreeSortID(node->left,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
  }
  else{
    node->right = insertToTreeSortID(node->right,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
  }

  return node;
}

// masukkan data yang diurutkan secara nama ke tree untuk semua wilayah
data *insertToTreeSortNama(data *node,int id,int tahun,int harga,char *nama,char *status,char *lokasi,char *kota,char *kapasitas){
  if(node==NULL) return newNode(id,tahun,harga,nama,status,lokasi,kota,kapasitas);

  if (strcmpi(nama , node->nama)<0){
    node->left = insertToTreeSortNama(node->left,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
  }
  else{
    node->right = insertToTreeSortNama(node->right,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
  }

  return node;
}

// masukkan data yang diurutkan secara status ke tree untuk semua wilayah
data *insertToTreeSortStatus(data *node,int id,int tahun,int harga,char *nama,char *status,char *lokasi,char *kota,char *kapasitas){
  if(node==NULL) return newNode(id,tahun,harga,nama,status,lokasi,kota,kapasitas);

  if (strcmpi(status , node->status)<0){
    node->left = insertToTreeSortStatus(node->left,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
  }
  else{
    node->right = insertToTreeSortStatus(node->right,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
  }

  return node;
}


// masukkan data yang diurutkan secara lokasi ke tree untuk semua wilayah
data *insertToTreeSortLokasi(data *node,int id,int tahun,int harga,char *nama,char *status,char *lokasi,char *kota,char *kapasitas){
  if(node==NULL) return newNode(id,tahun,harga,nama,status,lokasi,kota,kapasitas);

  if (strcmpi(lokasi , node->lokasi)<0){
    node->left = insertToTreeSortLokasi(node->left,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
  }
  else{
    node->right = insertToTreeSortLokasi(node->right,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
  }

  return node;
}

// masukkan data yang diurutkan secara ID ke tree untuk Depok
data *insertToTreeSortIDdepok(data *node,int id,int tahun,int harga,char *nama,char *status,char *lokasi,char *kota,char *kapasitas){
  if(strcmpi(kota,"Depok")==0){
      if(node==NULL) return newNode(id,tahun,harga,nama,status,lokasi,kota,kapasitas);

      if (id < node->id){
        node->left = insertToTreeSortIDdepok(node->left,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
      else{
        node->right = insertToTreeSortIDdepok(node->right,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
  }

  return node;
}

// masukkan data yang diurutkan secara nama ke tree untuk Depok
data *insertToTreeSortNamadepok(data *node,int id,int tahun,int harga,char *nama,char *status,char *lokasi,char *kota,char *kapasitas){
  if(strcmpi(kota,"Depok")==0){
      if(node==NULL) return newNode(id,tahun,harga,nama,status,lokasi,kota,kapasitas);

      if (strcmpi(nama , node->nama)<0){
        node->left = insertToTreeSortNamadepok(node->left,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
      else{
        node->right = insertToTreeSortNamadepok(node->right,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
  }
  return node;
}

// masukkan data yang diurutkan secara status ke tree untuk Depok
data *insertToTreeSortStatusdepok(data *node,int id,int tahun,int harga,char *nama,char *status,char *lokasi,char *kota,char *kapasitas){
  if(strcmpi(kota,"Depok")==0){
      if(node==NULL) return newNode(id,tahun,harga,nama,status,lokasi,kota,kapasitas);

      if (strcmpi(status , node->status)<0){
        node->left = insertToTreeSortStatusdepok(node->left,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
      else{
        node->right = insertToTreeSortStatusdepok(node->right,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
  }

  return node;
}

// masukkan data yang diurutkan secara lokasi ke tree untuk Depok
data *insertToTreeSortLokasidepok(data *node,int id,int tahun,int harga,char *nama,char *status,char *lokasi,char *kota,char *kapasitas){
  if(strcmpi(kota,"Depok")==0){
      if(node==NULL) return newNode(id,tahun,harga,nama,status,lokasi,kota,kapasitas);

      if (strcmpi(lokasi , node->lokasi)<0){
        node->left = insertToTreeSortLokasidepok(node->left,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
      else{
        node->right = insertToTreeSortLokasidepok(node->right,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
  }

  return node;
}

// masukkan data yang diurutkan secara ID ke tree untuk Bogor
data *insertToTreeSortIDbogor(data *node,int id,int tahun,int harga,char *nama,char *status,char *lokasi,char *kota,char *kapasitas){
  if(strcmpi(kota,"Bogor")==0){
      if(node==NULL) return newNode(id,tahun,harga,nama,status,lokasi,kota,kapasitas);

      if (id < node->id){
        node->left = insertToTreeSortIDbogor(node->left,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
      else{
        node->right = insertToTreeSortIDbogor(node->right,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
  }

  return node;
}

// masukkan data yang diurutkan secara Nama ke tree untuk Bogor
data *insertToTreeSortNamabogor(data *node,int id,int tahun,int harga,char *nama,char *status,char *lokasi,char *kota,char *kapasitas){
  if(strcmpi(kota,"Bogor")==0){
      if(node==NULL) return newNode(id,tahun,harga,nama,status,lokasi,kota,kapasitas);

      if (strcmpi(nama , node->nama)<0){
        node->left = insertToTreeSortNamabogor(node->left,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
      else{
        node->right = insertToTreeSortNamabogor(node->right,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
  }
  return node;
}

// masukkan data yang diurutkan secara status ke tree untuk Bogor
data *insertToTreeSortStatusbogor(data *node,int id,int tahun,int harga,char *nama,char *status,char *lokasi,char *kota,char *kapasitas){
  if(strcmpi(kota,"Bogor")==0){
      if(node==NULL) return newNode(id,tahun,harga,nama,status,lokasi,kota,kapasitas);

      if (strcmpi(status , node->status)<0){
        node->left = insertToTreeSortStatusbogor(node->left,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
      else{
        node->right = insertToTreeSortStatusbogor(node->right,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
  }

  return node;
}

// masukkan data yang diurutkan secara lokasi ke tree untuk Bogor
data *insertToTreeSortLokasibogor(data *node,int id,int tahun,int harga,char *nama,char *status,char *lokasi,char *kota,char *kapasitas){
  if(strcmpi(kota,"Bogor")==0){
      if(node==NULL) return newNode(id,tahun,harga,nama,status,lokasi,kota,kapasitas);

      if (strcmpi(lokasi , node->lokasi)<0){
        node->left = insertToTreeSortLokasibogor(node->left,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
      else{
        node->right = insertToTreeSortLokasibogor(node->right,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
  }

  return node;
}

// masukkan data yang diurutkan secara ID ke tree untuk Jakarta
data *insertToTreeSortIDjakarta(data *node,int id,int tahun,int harga,char *nama,char *status,char *lokasi,char *kota,char *kapasitas){
  if(strcmpi(kota,"Jakarta")==0){
      if(node==NULL) return newNode(id,tahun,harga,nama,status,lokasi,kota,kapasitas);

      if (id < node->id){
        node->left = insertToTreeSortIDjakarta(node->left,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
      else{
        node->right = insertToTreeSortIDjakarta(node->right,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
  }

  return node;
}

// masukkan data yang diurutkan secara Nama ke tree untuk Jakarta
data *insertToTreeSortNamajakarta(data *node,int id,int tahun,int harga,char *nama,char *status,char *lokasi,char *kota,char *kapasitas){
  if(strcmpi(kota,"Jakarta")==0){
      if(node==NULL) return newNode(id,tahun,harga,nama,status,lokasi,kota,kapasitas);

      if (strcmpi(nama , node->nama)<0){
        node->left = insertToTreeSortNamajakarta(node->left,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
      else{
        node->right = insertToTreeSortNamajakarta(node->right,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
  }
  return node;
}

// masukkan data yang diurutkan secara status ke tree untuk Jakarta
data *insertToTreeSortStatusjakarta(data *node,int id,int tahun,int harga,char *nama,char *status,char *lokasi,char *kota,char *kapasitas){
  if(strcmpi(kota,"Jakarta")==0){
      if(node==NULL) return newNode(id,tahun,harga,nama,status,lokasi,kota,kapasitas);

      if (strcmpi(status , node->status)<0){
        node->left = insertToTreeSortStatusjakarta(node->left,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
      else{
        node->right = insertToTreeSortStatusjakarta(node->right,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
  }

  return node;
}

// masukkan data yang diurutkan secara lokasi ke tree untuk Jakarta
data *insertToTreeSortLokasijakarta(data *node,int id,int tahun,int harga,char *nama,char *status,char *lokasi,char *kota,char *kapasitas){
  if(strcmpi(kota,"Jakarta")==0){
      if(node==NULL) return newNode(id,tahun,harga,nama,status,lokasi,kota,kapasitas);

      if (strcmpi(lokasi , node->lokasi)<0){
        node->left = insertToTreeSortLokasijakarta(node->left,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
      else{
        node->right = insertToTreeSortLokasijakarta(node->right,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
  }

  return node;
}

// masukkan data yang diurutkan secara ID ke tree untuk Bekasi
data *insertToTreeSortIDbekasi(data *node,int id,int tahun,int harga,char *nama,char *status,char *lokasi,char *kota,char *kapasitas){
  if(strcmpi(kota,"Bekasi")==0){
      if(node==NULL) return newNode(id,tahun,harga,nama,status,lokasi,kota,kapasitas);

      if (id < node->id){
        node->left = insertToTreeSortIDbekasi(node->left,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
      else{
        node->right = insertToTreeSortIDbekasi(node->right,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
  }

  return node;
}

// masukkan data yang diurutkan secara Nama ke tree untuk Bekasi
data *insertToTreeSortNamabekasi(data *node,int id,int tahun,int harga,char *nama,char *status,char *lokasi,char *kota,char *kapasitas){
  if(strcmpi(kota,"Bekasi")==0){
      if(node==NULL) return newNode(id,tahun,harga,nama,status,lokasi,kota,kapasitas);

      if (strcmpi(nama , node->nama)<0){
        node->left = insertToTreeSortNamabekasi(node->left,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
      else{
        node->right = insertToTreeSortNamabekasi(node->right,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
  }
  return node;
}

// masukkan data yang diurutkan secara status ke tree untuk Bekasi
data *insertToTreeSortStatusbekasi(data *node,int id,int tahun,int harga,char *nama,char *status,char *lokasi,char *kota,char *kapasitas){
  if(strcmpi(kota,"Bekasi")==0){
      if(node==NULL) return newNode(id,tahun,harga,nama,status,lokasi,kota,kapasitas);

      if (strcmpi(status , node->status)<0){
        node->left = insertToTreeSortStatusbekasi(node->left,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
      else{
        node->right = insertToTreeSortStatusbekasi(node->right,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
  }

  return node;
}

// masukkan data yang diurutkan secara lokasi ke tree untuk Bekasi
data *insertToTreeSortLokasibekasi(data *node,int id,int tahun,int harga,char *nama,char *status,char *lokasi,char *kota,char *kapasitas){
  if(strcmpi(kota,"Bekasi")==0){
      if(node==NULL) return newNode(id,tahun,harga,nama,status,lokasi,kota,kapasitas);

      if (strcmpi(lokasi , node->lokasi)<0){
        node->left = insertToTreeSortLokasibekasi(node->left,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
      else{
        node->right = insertToTreeSortLokasibekasi(node->right,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
  }

  return node;
}

// masukkan data yang diurutkan secara ID ke tree untuk Tangerang
data *insertToTreeSortIDtangerang(data *node,int id,int tahun,int harga,char *nama,char *status,char *lokasi,char *kota,char *kapasitas){
  if(strcmpi(kota,"Tangerang")==0){
      if(node==NULL) return newNode(id,tahun,harga,nama,status,lokasi,kota,kapasitas);

      if (id < node->id){
        node->left = insertToTreeSortIDtangerang(node->left,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
      else{
        node->right = insertToTreeSortIDtangerang(node->right,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
      }
  }

  return node;
}

// masukkan data yang diurutkan secara nama ke tree untuk Tangerang
data *insertToTreeSortNamatangerang(data *node,int id,int tahun,int harga,char *nama,char *status,char *lokasi,char *kota,char *kapasitas){
  if(strcmpi(kota,"Tangerang")==0){
    if(node==NULL) return newNode(id,tahun,harga,nama,status,lokasi,kota,kapasitas);

    if (strcmpi(nama , node->nama)<0){
      node->left = insertToTreeSortNamatangerang(node->left,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
    }
    else{
      node->right = insertToTreeSortNamatangerang(node->right,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
    }
  }
  return node;
}

// masukkan data yang diurutkan secara status ke tree untuk Tangerang
data *insertToTreeSortStatustangerang(data *node,int id,int tahun,int harga,char *nama,char *status,char *lokasi,char *kota,char *kapasitas){
  if(strcmpi(kota,"Tangerang")==0){
    if(node==NULL) return newNode(id,tahun,harga,nama,status,lokasi,kota,kapasitas);

    if (strcmpi(status , node->status)<0){
      node->left = insertToTreeSortStatustangerang(node->left,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
    }
    else{
      node->right = insertToTreeSortStatustangerang(node->right,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
    }
  }
  return node;
}

// masukkan data yang diurutkan secara lokasi ke tree untuk Tangerang
data *insertToTreeSortLokasitangerang(data *node,int id,int tahun,int harga,char *nama,char *status,char *lokasi,char *kota,char *kapasitas){
  if(strcmpi(kota,"Tangerang")==0){
    if(node==NULL) return newNode(id,tahun,harga,nama,status,lokasi,kota,kapasitas);

    if (strcmpi(lokasi , node->lokasi)<0){
      node->left = insertToTreeSortLokasitangerang(node->left,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
    }
    else{
      node->right = insertToTreeSortLokasitangerang(node->right,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
    }
  }
  return node;
}



// Interface
void 
garis(){
    printf("==========================================\n");
}

void semuawilayah(){

    system("cls");
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("%c  Selamat Datang di Mobil Galaxy  %c\n",186,186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    printf("1. Sewa Mobil\n");
    printf("2. Cari Mobil\n");
    printf("3. Tampilkan Daftar Sewaan\n");
    printf("4. Tambah Mobil (Admin)\n");
    printf("0. Kembali\n");
}

void tampil(){
    system("cls");
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("%c           Sewa Mobil (ID)        %c\n",186,186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    printf("1. Sorting Semua Mobil Berdasarkan ID dan Sewa Mobil\n");
    printf("2. Sorting Semua Mobil Berdasarkan Nama dan Sewa Mobil\n");
    printf("3. Sorting Semua Mobil Berdasarkan Status dan Sewa Mobil\n");
    printf("4. Sorting Semua Mobil Berdasarkan Lokasi dan Sewa Mobil\n");
    printf("0. Kembali\n");
}

void search(){
    system("cls");
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("%c            Cari Mobil\t           %c\n",186,186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    printf("1. Cari Berdasarkan ID Mobil (Hanya untuk dilihat)\n");
    printf("2. Cari Berdasarkan Nama Mobil (Hanya untuk dilihat)\n");
    printf("3. Cari Berdasarkan Status Mobil (Hanya untuk dilihat)\n");
    printf("4. Cari Berdasarkan Harga Mobil (Hanya untuk dilihat)\n");
    printf("5. Cari Berdasarkan Tahun Mobil (Hanya untuk dilihat)\n");
    printf("0. Kembali\n");
}
void about(){
    system("cls");
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("%c           Mobil Galaxy           %c\n",186,186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

}
void tampilmobil(){
    system("cls");
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("%c           Mobil Galaxy           %c\n",186,186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
}

void listmobil(){
  system("cls");
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
  printf("%c           Mobil yang terdaftar\t        %c\n",186,186);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

}

void menu(){
    system("cls");
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("%c            Daftar Wilayah yang           %c\n",186,186);
    printf("%c    Mobilnya terdaftar di Mobil Galaxy    %c\n",186,186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

    printf("1. Lihat Mobil yang Tersedia di Depok\n");
    printf("2. Lihat Mobil yang Tersedia di Bogor\n");
    printf("3. Lihat Mobil yang Tersedia di Jakarta\n" );
    printf("4. Lihat Mobil yang Tersedia di Bekasi\n");
    printf("5. Lihat Mobil yang Tersedia di Tangerang\n" );
    printf("6. Sewa(Semua Wilayah)\n" );
    printf("0. Keluar\n" );
}

void mobiltangerang(){
  system("cls");
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
  printf("%c     Daftar Mobil di Tangerang    %c\n",186,186);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
  printf("1. Sorting Berdasarkan ID (Hanya untuk dilihat)\n");
  printf("2. Sorting Berdasarkan Nama (Hanya untuk dilihat)\n");
  printf("3. Sorting Berdasarkan Status (Hanya untuk dilihat)\n");
  printf("4. Sorting Berdasarkan Lokasi (Hanya untuk dilihat)\n");
  printf("0. Kembali\n");
}


void mobildepok(){
  system("cls");
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
  printf("%c       Daftar Mobil di Depok      %c\n",186,186);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
  printf("1. Sorting Berdasarkan ID (Hanya untuk dilihat)\n");
  printf("2. Sorting Berdasarkan Nama (Hanya untuk dilihat)\n");
  printf("3. Sorting Berdasarkan Status (Hanya untuk dilihat)\n");
  printf("4. Sorting Berdasarkan Lokasi (Hanya untuk dilihat)\n");
  printf("0. Kembali\n");
}


void mobiljakarta(){
  system("cls");
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
  printf("%c       Daftar Mobil di Jakarta    %c\n",186,186);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
  printf("1. Sorting Berdasarkan ID (Hanya untuk dilihat)\n");
  printf("2. Sorting Berdasarkan Nama (Hanya untuk dilihat)\n");
  printf("3. Sorting Berdasarkan Status (Hanya untuk dilihat)\n");
  printf("4. Sorting Berdasarkan Lokasi (Hanya untuk dilihat)\n");
  printf("0. Kembali\n");
}


void mobilbogor(){
  system("cls");
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
  printf("%c        Daftar Mobil di Bogor     %c\n",186,186);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
  printf("1. Sorting Berdasarkan ID (Hanya untuk dilihat)\n");
  printf("2. Sorting Berdasarkan Nama (Hanya untuk dilihat)\n");
  printf("3. Sorting Berdasarkan Status (Hanya untuk dilihat)\n");
  printf("4. Sorting Berdasarkan Lokasi (Hanya untuk dilihat)\n");
  printf("0. Kembali\n");
}


void mobilbekasi(){
  system("cls");
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
  printf("%c       Daftar Mobil di Bekasi     %c\n",186,186);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
  printf("1. Sorting Berdasarkan ID (Hanya untuk dilihat)\n");
  printf("2. Sorting Berdasarkan Nama (Hanya untuk dilihat)\n");
  printf("3. Sorting Berdasarkan Status (Hanya untuk dilihat)\n");
  printf("4. Sorting Berdasarkan Lokasi (Hanya untuk dilihat)\n");
  printf("0. Kembali\n");
}

void searchAdv(){
    system("cls");
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("%c            Cari Mobil\t           %c\n",186,186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
}


void tambahmobil(){
  system("cls");
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
  printf("%c           Tambah Mobil           %c\n",186,186);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
}

void sewaan(){
  system("cls");
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
  printf("%c            Sewaan Mobil          %c\n",186,186);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
}



int main()
{
    // Linked list
    data *head, *now,*node; // penanda dalam linked list
    head = now = NULL; // diatur menjadi null

    // tree untuk mengurutkan semua wilayah
    data *treeid=NULL;
    data *treenama=NULL;
    data *treestatus=NULL;
    data *treelokasi=NULL;

    // tree untuk mengurutkan depok
    data *treeiddepok=NULL;
    data *treenamadepok=NULL;
    data *treestatusdepok=NULL;
    data *treelokasidepok=NULL;

    // tree untuk mengurutkan bogor
    data *treeidbogor=NULL;
    data *treenamabogor=NULL;
    data *treestatusbogor=NULL;
    data *treelokasibogor=NULL;

    // tree untuk mengurutkan jakarta
    data *treeidjakarta=NULL;
    data *treenamajakarta=NULL;
    data *treestatusjakarta=NULL;
    data *treelokasijakarta=NULL;

    // tree untuk mengurutkan bekasi
    data *treeidbekasi=NULL;
    data *treenamabekasi=NULL;
    data *treestatusbekasi=NULL;
    data *treelokasibekasi=NULL;

    // tree untuk mengurutkan tangerang
    data *treeidtangerang=NULL;
    data *treenamatangerang=NULL;
    data *treestatustangerang=NULL;
    data *treelokasitangerang=NULL;

    //Variable yang akan dimasukkan ke txt
    char nama[1000],nama_2[1000], lokasi[1000], status[1000],kota[100],kapasitas[1000],usernames[1000];
    int id,id_2, tahun,harga,durasi,total,date,month,year;
    

    //Variable program
    int counter=1,randomNumber,i,position,jumlah=0,jawaban;
    int pilih, pilihTampil, pilihUrut, pilihCari,pilihMenu;
    char username[100],password[100],admin[10];
    bool check;
    int numresult=0;
  

    //baca data di txt
    FILE *fp;
    fp = fopen("datacar.txt", "a+");
    while(!feof(fp)){
        fscanf(fp, "%d#%[^#]#%[^#]#%[^#]#%[^#]#%d#%[^#]#%d\n", &id, &nama, &status, &lokasi,&kota,&tahun,&kapasitas,&harga);fflush(stdin);

        // Linked List
        node = (struct data*) malloc(sizeof(struct data));
        node -> next= NULL;

        if(head==NULL)// jika head kosong
        {
          head= node; // buat node baru dengan mengasign head
        }
        else{ // jika head sudah berisi
          now = head; // membuat data berada di head
          while(now->next!=NULL){ // selama data setelah now ada isinya
            now = now->next;  // pindahkan now ke data setelah now
          }
          now->next= node; // buat node baru jika setelah now tidak ada data lagi
        }

        //Simpan data untuk sorting
        node->id = id;
        node->tahun = tahun;
        node->harga = harga;
        strcpy(node->nama, nama);
        strcpy(node->status, status);
        strcpy(node->lokasi, lokasi);
        strcpy(node->kota, kota);
        strcpy(node->kapasitas, kapasitas);

        // memasukkan data ke tree untuk semua wilayah
        treeid=insertToTreeSortID(treeid,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
        treenama=insertToTreeSortNama(treenama,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
        treestatus=insertToTreeSortStatus(treestatus,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
        treelokasi=insertToTreeSortLokasi(treelokasi,id,tahun,harga,nama,status,lokasi,kota,kapasitas);

        // memasukkan data ke tree untuk Depok
        treeiddepok=insertToTreeSortIDdepok(treeiddepok,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
        treenamadepok=insertToTreeSortNamadepok(treenamadepok,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
        treestatusdepok=insertToTreeSortStatusdepok(treestatusdepok,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
        treelokasidepok=insertToTreeSortLokasidepok(treelokasidepok,id,tahun,harga,nama,status,lokasi,kota,kapasitas);

        // memasukkan data ke tree untuk Bogor
        treeidbogor=insertToTreeSortIDbogor(treeidbogor,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
        treestatusbogor=insertToTreeSortStatusbogor(treestatusbogor,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
        treenamabogor=insertToTreeSortNamabogor(treenamabogor,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
        treelokasibogor=insertToTreeSortLokasibogor(treelokasibogor,id,tahun,harga,nama,status,lokasi,kota,kapasitas);

        // memasukkan data ke tree untuk Jakarta
        treeidjakarta=insertToTreeSortIDjakarta(treeidjakarta,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
        treenamajakarta=insertToTreeSortNamajakarta(treenamajakarta,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
        treestatusjakarta=insertToTreeSortStatusjakarta(treestatusjakarta,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
        treelokasijakarta=insertToTreeSortLokasijakarta(treelokasijakarta,id,tahun,harga,nama,status,lokasi,kota,kapasitas);

        // memasukkan data ke tree untuk Bekasi
        treeidbekasi=insertToTreeSortIDbekasi(treeidbekasi,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
        treenamabekasi=insertToTreeSortNamabekasi(treenamabekasi,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
        treestatusbekasi=insertToTreeSortStatusbekasi(treestatusbekasi,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
        treelokasibekasi=insertToTreeSortLokasibekasi(treelokasibekasi,id,tahun,harga,nama,status,lokasi,kota,kapasitas);

        // memasukkan data ke tree untuk Tangerang
        treeidtangerang=insertToTreeSortIDtangerang(treeidtangerang,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
        treenamatangerang=insertToTreeSortNamatangerang(treenamatangerang,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
        treestatustangerang=insertToTreeSortStatustangerang(treestatustangerang,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
        treelokasitangerang=insertToTreeSortLokasitangerang(treelokasitangerang,id,tahun,harga,nama,status,lokasi,kota,kapasitas);


        //Simpan data untuk searching
        mobil[counter].id = id;
        mobil[counter].tahun = tahun;
        mobil[counter].harga = harga;
        strcpy(mobil[counter].nama, nama);
        strcpy(mobil[counter].status, status);
        strcpy(mobil[counter].lokasi, lokasi);
        strcpy(mobil[counter].kota, kota);
        strcpy(mobil[counter].kapasitas, kapasitas);

        counter++;
    }
    fclose(fp);

    // About Mobil Galaxy
    about();
    printf("Mobil Galaxy adalah program yang membantu masyarakat\n" );
    printf("untuk melakukan penyewaan mobil di area JABODETABEK.\n" );
    printf("\n" );
    printf("Tekan untuk melanjutkan..." );
    getchar();
    

    //Main Menu
    bool exit = false, quit = false, stop = false;
 
    while(exit==false)
    {
        menu();
        printf("Pilih : "); scanf("%d", &pilihMenu); fflush(stdin);

        switch(pilihMenu)
        {
            case 0 : //back
                return 0;
            case 1: //  depok
                quit = false;
                while(quit==false)
                {
                    system("cls");
                    mobildepok();
                    printf("Pilih : "); scanf("%d", &pilihTampil); fflush(stdin);
                    switch(pilihTampil)
                    {
                        case 0 : // kembali
                            system("cls");
                            quit = true;
                            break;
                        case 1 : // tampilkan berdasarkan id
                            tampilmobil();
                            printListInorder(treeiddepok);
                            garis();
                            
                            printf("Tekan apapun untuk lanjut. . .");
                            getchar();
                            break;
                        case 2 : // tampilkan berdasarkan nama
                            tampilmobil();
                            printListInorder(treenamadepok);
                            garis();
                            printf("Tekan apapun untuk lanjut. . .");
                            getchar();
                            break;
                        case 3 : // tampilkan berdasarkan status
                            tampilmobil();
                            printListInorder(treestatusdepok);
                            garis();
                            printf("Tekan apapun untuk lanjut. . .");
                            getchar();
                            break;
                        case 4:// tampilkan berdasarkan lokasi
                            tampilmobil();
                            printListInorder(treelokasidepok);
                            garis();
                            printf("Tekan apapun untuk lanjut. . .");
                            getchar();
                            break;
                        default:
                            printf("Pilihan Salah!\n"); getchar();
                            break;
                    }
                }
            break;

            case 2: // bogor
                quit = false;
                while(quit==false)
                {
                    system("cls");
                    mobilbogor();
                    printf("Pilih : "); scanf("%d", &pilihTampil); fflush(stdin);
                    switch(pilihTampil)
                    {
                        case 0 : // kembali
                            system("cls");
                            quit = true;
                            break;
                        case 1 : // tampilkan berdasarkan id
                            tampilmobil();
                            printListInorder(treeidbogor);
                            garis();
                            

                            printf("Tekan apapun untuk lanjut. . .");
                            getchar();
                            break;
                        case 2 : // tampilkan berdasarkan nama
                            tampilmobil();
                            printListInorder(treenamabogor);
                            garis();
                            printf("Tekan apapun untuk lanjut. . .");
                            getchar();
                            break;
                        case 3 : // tampilkan berdasarkan status
                            tampilmobil();
                            printListInorder(treestatusbogor);
                            garis();
                            printf("Tekan apapun untuk lanjut. . .");
                            getchar();
                            break;
                        case 4:// tampilkan berdasarkan lokasi
                            tampilmobil();
                            printListInorder(treelokasibogor);
                            garis();
                            printf("Tekan apapun untuk lanjut. . .");
                            getchar();
                            break;
                        default:
                            printf("Pilihan Salah!\n"); getchar();
                            break;
                    }
                }
            break;

            case 3: //jkt
                quit = false;
                while(quit==false)
                {
                    system("cls");
                    mobiljakarta();
                    printf("Pilih : "); scanf("%d", &pilihTampil); fflush(stdin);
                    switch(pilihTampil)
                    {
                        case 0 : // kembali
                            system("cls");
                            quit = true;
                            break;
                        case 1 : // tampilkan berdasarkan id
                            tampilmobil();
                            printListInorder(treeidjakarta);
                            garis();

                            printf("Tekan apapun untuk lanjut. . .");
                            getchar();
                            break;
                        case 2 : // tampilkan berdasarkan nama
                            tampilmobil();
                            printListInorder(treenamajakarta);
                            garis();
                            printf("Tekan apapun untuk lanjut. . .");
                            getchar();
                            break;
                        case 3 : // tampilkan berdasarkan status
                            tampilmobil();
                            printListInorder(treestatusjakarta);
                            garis();
                            printf("Tekan apapun untuk lanjut. . .");
                            getchar();
                            break;
                        case 4:// tampilkan berdasarkan lokasi
                            tampilmobil();
                            printListInorder(treelokasijakarta);
                            garis();
                            printf("Tekan apapun untuk lanjut. . .");
                            getchar();
                            break;
                        default:
                            printf("Pilihan Salah!\n"); getchar();
                            break;
                    }
                }
            break;

            case 4: //bekasi
                quit = false;
                while(quit==false)
                {
                    system("cls");
                    mobilbekasi();
                    printf("Pilih : "); scanf("%d", &pilihTampil); fflush(stdin);
                    switch(pilihTampil)
                    {
                        case 0 : // kembali
                            system("cls");
                            quit = true;
                            break;
                        case 1 : // tampilkan berdasarkan id
                            tampilmobil();
                            printListInorder(treeidbekasi);
                            garis();

                            printf("Tekan apapun untuk lanjut. . .");
                            getchar();
                            break;
                        case 2 : // tampilkan berdasarkan nama
                            tampilmobil();
                            printListInorder(treenamabekasi);
                            garis();
                            printf("Tekan apapun untuk lanjut. . .");
                            getchar();
                            break;
                        case 3 : // tampilkan berdasarkan status
                            tampilmobil();
                            printListInorder(treestatusbekasi);
                            garis();
                            printf("Tekan apapun untuk lanjut. . .");
                            getchar();
                            break;
                        case 4:// tampilkan berdasarkan lokasi
                            tampilmobil();
                            printListInorder(treelokasibekasi);
                            garis();
                            printf("Tekan apapun untuk lanjut. . .");
                            getchar();
                            break;
                        default:
                            printf("Pilihan Salah!\n"); getchar();
                            break;
                    }
                }
            break;

            case 5 : //tangerang
                quit = false;
                while(quit==false)
                {
                    system("cls");
                    mobiltangerang();
                    printf("Pilih : "); scanf("%d", &pilihTampil); fflush(stdin);
                    switch(pilihTampil)
                    {
                        case 0 : // kembali
                            system("cls");
                            quit = true;
                            break;
                        case 1 : // tampilkan berdasarkan id
                            tampilmobil();
                            printListInorder(treeidtangerang);
                            garis();

                            printf("Tekan apapun untuk lanjut. . .");
                            getchar();
                            break;
                        case 2 : // tampilkan berdasarkan nama
                            tampilmobil();
                            printListInorder(treenamatangerang);
                            garis();
                            printf("Tekan apapun untuk lanjut. . .");
                            getchar();
                            break;
                        case 3 : // tampilkan berdasarkan status
                            tampilmobil();
                            printListInorder(treestatustangerang);
                            garis();
                            printf("Tekan apapun untuk lanjut. . .");
                            getchar();
                            break;
                        case 4:// tampilkan berdasarkan lokasi
                            tampilmobil();
                            printListInorder(treelokasitangerang);
                            garis();
                            printf("Tekan apapun untuk lanjut. . .");
                            getchar();
                            break;
                        default:
                            printf("Pilihan Salah!\n"); getchar();
                            break;
                    }
                }
            break;

            case 6: // semua wilayah
                quit = false;
                while(quit==false)
                {
                    system("cls");
                    semuawilayah();
                    printf("Pilih : "); scanf("%d", &pilih); fflush(stdin);

                    switch(pilih)
                    {
                        case 0 : //back
                            system("cls");
                            quit =true;
                            break;
                        case 1 : //lihat mobil

                            stop = false;
                            while(stop == false)
                            {
                                system("cls");
                                tampil();
                                printf("Pilih : "); scanf("%d", &pilihTampil); fflush(stdin);

                                switch(pilihTampil)
                                {
                                    case 0 : // kembali
                                        system("cls");
                                        stop = true;
                                        break;
                                    case 1 : // tampilkan berdasarkan id
                                        tampilmobil();
                                        printListInorder(treeid);
                                        garis();
                                        printf("ID mobil yang dicari :");
                                        scanf("%d", &id);fflush(stdin);

                                        position=-1;
                                        position = sequentialSearchID(id, counter); // memanggil fungsi searching dengan id
                                        if(position != -1)
										{ // jika data ditemukan
                                            printf("\n");
	                                            printf("ID                  			   : %d\n", mobil[position].id);
	                                            printf("Nama                			   : %s\n", mobil[position].nama);
	                                            printf("Status              			   : %s\n", mobil[position].status);
	                                            printf("Lokasi              			   : %s\n", mobil[position].lokasi);
	                                            printf("Kota\t\t\t\t\t   : %s\n", mobil[position].kota);
	                                            printf("Tahun               			   : %d\n", mobil[position].tahun);
	                                            printf("Kapasitas           			   : %s\n", mobil[position].kapasitas);
	                                            printf("Harga\t\t\t\t\t   : Rp %d,-\n", mobil[position].harga);
	                                            
	                                            printf("Masukkan Username\t\t\t   : ");
	                                            scanf("%s",&mobil[position].usernames);
	                                            printf("Tanggal\t\t\t\t\t   : ");
	                                            scanf("%d",&mobil[position].date);
	                                            printf("Bulan\t\t\t\t\t   : ");
	                                            scanf("%d",&mobil[position].month);
	                                            printf("Tahun\t\t\t\t\t   : ");
	                                            scanf("%d",&mobil[position].year);
	                                            printf("Masukkan durasi(hari)\t\t\t   : ");
	                                            scanf("%d", &mobil[position].durasi); 
	                                          
	                                            mobil[position].total= mobil[position].harga*mobil[position].durasi;
	                                            printf("Total Harga\t\t\t\t   : Rp %d,-\n",mobil[position].total);
	                                            system("pause");
	                                            getchar();
	                                            
	                                            do{
	                                            	system("cls");
	                                            	printf("\nKonfirmasi pembayaran atas nama %s (1/2)  : ",mobil[position].usernames);
	                                            	printf("\n1. Ya");
	                                            	printf("\n2. Tidak");
	                                            	printf("\nPilih : ");
													scanf("%d",&jawaban);
													
													switch(jawaban)
													{
														case 1 :
												
															printf("\nTransaksi Berhasil");
															//masukkan data ke txt
						                                    fp = fopen("datasewacar.txt", "a+");
						                                    fprintf(fp, "%s#%d#%s#%s#%s#%s#%d#%s#%d#%d#%d#%d#%d#%d\n", mobil[position].usernames,mobil[position].id, mobil[position].nama, mobil[position].status, mobil[position].lokasi,mobil[position].kota,mobil[position].tahun,mobil[position].kapasitas,mobil[position].harga
															,mobil[position].durasi,mobil[position].total,mobil[position].date,mobil[position].month,mobil[position].year);fflush(stdin);
						                                    fclose(fp);
						                                    printf("\nData telah berhasil ditambahkan!\n");
						                                    printf("Tekan apapun untuk lanjut. . .");
						                                    
						
						                                    
															return 0;
														case 2: 
															printf("\nTransaksi Dibatalkan");
															return 0;															
															
													}
												}while(jawaban!=2); break;
										
										} 
                                        printf("Tekan apapun untuk lanjut. . .");
                                        getchar();
                                        break;
                                        
                                    case 2 : // tampilkan berdasarkan nama
                                        tampilmobil();
                                        printListInorder(treenama);
                                        garis();
                                        
                                        printf("ID mobil yang dicari :");
                                        scanf("%d", &id);fflush(stdin);

                                        position=-1;
                                        position = sequentialSearchID(id, counter); // memanggil fungsi searching dengan id
                                        if(position != -1)
										{ // jika data ditemukan
                                           printf("\n");
	                                            printf("ID                  			   : %d\n", mobil[position].id);
	                                            printf("Nama                			   : %s\n", mobil[position].nama);
	                                            printf("Status              			   : %s\n", mobil[position].status);
	                                            printf("Lokasi              			   : %s\n", mobil[position].lokasi);
	                                            printf("Kota\t\t\t\t\t   : %s\n", mobil[position].kota);
	                                            printf("Tahun               			   : %d\n", mobil[position].tahun);
	                                            printf("Kapasitas           			   : %s\n", mobil[position].kapasitas);
	                                            printf("Harga\t\t\t\t\t   : Rp %d,-\n", mobil[position].harga);
	                                            
	                                            printf("Masukkan Username\t\t\t   : ");
	                                            scanf("%s",&mobil[position].usernames);
	                                            printf("Tanggal\t\t\t\t\t   : ");
	                                            scanf("%d",&mobil[position].date);
	                                            printf("Bulan\t\t\t\t\t   : ");
	                                            scanf("%d",&mobil[position].month);
	                                            printf("Tahun\t\t\t\t\t   : ");
	                                            scanf("%d",&mobil[position].year);
	                                            printf("Masukkan durasi\t\t\t\t   : ");
	                                            scanf("%d", &mobil[position].durasi); 
	                                          
	                                            mobil[position].total= mobil[position].harga*mobil[position].durasi;
	                                            printf("Total Harga\t\t\t\t   : Rp %d,-\n",mobil[position].total);
	                                            system("pause");
	                                            getchar();
	                                            
	                                            do{
	                                            	system("cls");
	                                            	printf("\nKonfirmasi pembayaran atas nama %s : ",mobil[position].usernames);
	                                            	printf("\n1. Ya");
	                                            	printf("\n2. Tidak");
	                                            	printf("\nPilih : ");
													scanf("%d",&jawaban);
													
													switch(jawaban)
													{
														case 1 :
												
															printf("\nTransaksi Berhasil");
															//masukkan data ke txt
						                                    fp = fopen("datasewacar.txt", "a+");
						                                    fprintf(fp, "%s#%d#%s#%s#%s#%s#%d#%s#%d#%d#%d#%d#%d#%d\n", mobil[position].usernames,mobil[position].id, mobil[position].nama, mobil[position].status, mobil[position].lokasi,mobil[position].kota,mobil[position].tahun,mobil[position].kapasitas,mobil[position].harga
															,mobil[position].durasi,mobil[position].total,mobil[position].date,mobil[position].month,mobil[position].year);fflush(stdin);
						                                    fclose(fp);
						                                    printf("\nData telah berhasil ditambahkan!\n");
						                                    printf("Tekan apapun untuk lanjut. . .");
						                                    
						
						                                    
															return 0;
														case 2: 
															printf("\nTransaksi Dibatalkan");															
															return 0;
													}
												}while(jawaban!=2); break;
										
										}  
                                        printf("Tekan apapun untuk lanjut. . .");
                                        getchar();
                                        break;
                                    case 3 : // tampilkan berdasarkan status
                                        tampilmobil();
                                        printListInorder(treestatus);
                                        garis();
                                        
                                        printf("ID mobil yang dicari :");
                                        scanf("%d", &id);fflush(stdin);

                                        position=-1;
                                        position = sequentialSearchID(id, counter); // memanggil fungsi searching dengan id
                                        if(position != -1)
										{ // jika data ditemukan
                                           printf("\n");
	                                            printf("ID                  			   : %d\n", mobil[position].id);
	                                            printf("Nama                			   : %s\n", mobil[position].nama);
	                                            printf("Status              			   : %s\n", mobil[position].status);
	                                            printf("Lokasi              			   : %s\n", mobil[position].lokasi);
	                                            printf("Kota\t\t\t\t\t   : %s\n", mobil[position].kota);
	                                            printf("Tahun               			   : %d\n", mobil[position].tahun);
	                                            printf("Kapasitas           			   : %s\n", mobil[position].kapasitas);
	                                            printf("Harga\t\t\t\t\t   : Rp %d,-\n", mobil[position].harga);
	                                            
	                                            printf("Masukkan Username\t\t\t   : ");
	                                            scanf("%s",&mobil[position].usernames);
	                                            printf("Tanggal\t\t\t\t\t   : ");
	                                            scanf("%d",&mobil[position].date);
	                                            printf("Bulan\t\t\t\t\t   : ");
	                                            scanf("%d",&mobil[position].month);
	                                            printf("Tahun\t\t\t\t\t   : ");
	                                            scanf("%d",&mobil[position].year);
	                                            printf("Masukkan durasi\t\t\t\t   : ");
	                                            scanf("%d", &mobil[position].durasi); 
	                                          
	                                            mobil[position].total= mobil[position].harga*mobil[position].durasi;
	                                            printf("Total Harga\t\t\t\t   : Rp %d,-\n",mobil[position].total);
	                                            system("pause");
	                                            getchar();
	                                            
	                                            do{
	                                            	system("cls");
	                                            	printf("\nKonfirmasi pembayaran atas nama %s : ",mobil[position].usernames);
	                                            	printf("\n1. Ya");
	                                            	printf("\n2. Tidak");
	                                            	printf("\nPilih : ");
													scanf("%d",&jawaban);
													
													switch(jawaban)
													{
														case 1 :
												
															printf("\nTransaksi Berhasil");
															//masukkan data ke txt
						                                    fp = fopen("datasewacar.txt", "a+");
						                                    fprintf(fp, "%s#%d#%s#%s#%s#%s#%d#%s#%d#%d#%d#%d#%d#%d\n", mobil[position].usernames,mobil[position].id, mobil[position].nama, mobil[position].status, mobil[position].lokasi,mobil[position].kota,mobil[position].tahun,mobil[position].kapasitas,mobil[position].harga
															,mobil[position].durasi,mobil[position].total,mobil[position].date,mobil[position].month,mobil[position].year);fflush(stdin);
						                                    fclose(fp);
						                                    printf("\nData telah berhasil ditambahkan!\n");
						                                    printf("Tekan apapun untuk lanjut. . .");
						                                    
						
						                                    
															return 0;
														case 2: 
															printf("\nTransaksi Dibatalkan");															
															return 0;
													}
												}while(jawaban!=2); break;
										
										}  
										
                                        printf("Tekan apapun untuk lanjut. . .");
                                        getchar();
                                        break;
                                    case 4:// tampilkan berdasarkan lokasi
                                        tampilmobil();
                                        printListInorder(treelokasi);
                                        garis();
                                        
                                        printf("ID mobil yang dicari :");
                                        scanf("%d", &id);fflush(stdin);

                                        position=-1;
                                        position = sequentialSearchID(id, counter); // memanggil fungsi searching dengan id
                                        if(position != -1)
										{ // jika data ditemukan
                                           printf("\n");
	                                            printf("ID                  			   : %d\n", mobil[position].id);
	                                            printf("Nama                			   : %s\n", mobil[position].nama);
	                                            printf("Status              			   : %s\n", mobil[position].status);
	                                            printf("Lokasi              			   : %s\n", mobil[position].lokasi);
	                                            printf("Kota\t\t\t\t\t   : %s\n", mobil[position].kota);
	                                            printf("Tahun               			   : %d\n", mobil[position].tahun);
	                                            printf("Kapasitas           			   : %s\n", mobil[position].kapasitas);
	                                            printf("Harga\t\t\t\t\t   : Rp %d,-\n", mobil[position].harga);
	                                            
	                                            printf("Masukkan Username\t\t\t   : ");
	                                            scanf("%s",&mobil[position].usernames);
	                                            printf("Tanggal\t\t\t\t\t   : ");
	                                            scanf("%d",&mobil[position].date);
	                                            printf("Bulan\t\t\t\t\t   : ");
	                                            scanf("%d",&mobil[position].month);
	                                            printf("Tahun\t\t\t\t\t   : ");
	                                            scanf("%d",&mobil[position].year);
	                                            printf("Masukkan durasi\t\t\t\t   : ");
	                                            scanf("%d", &mobil[position].durasi); 
	                                          
	                                            mobil[position].total= mobil[position].harga*mobil[position].durasi;
	                                            printf("Total Harga\t\t\t\t   : Rp %d,-\n",mobil[position].total);
	                                            system("pause");
	                                            getchar();
	                                            
	                                            do{
	                                            	system("cls");
	                                            	printf("\nKonfirmasi pembayaran atas nama %s : ",mobil[position].usernames);
	                                            	printf("\n1. Ya");
	                                            	printf("\n2. Tidak");
	                                            	printf("\nPilih : ");
													scanf("%d",&jawaban);
													
													switch(jawaban)
													{
														case 1 :
												
															printf("\nTransaksi Berhasil");
															//masukkan data ke txt
						                                    fp = fopen("datasewacar.txt", "a+");
						                                    fprintf(fp, "%s#%d#%s#%s#%s#%s#%d#%s#%d#%d#%d#%d#%d#%d\n", mobil[position].usernames,mobil[position].id, mobil[position].nama, mobil[position].status, mobil[position].lokasi,mobil[position].kota,mobil[position].tahun,mobil[position].kapasitas,mobil[position].harga
															,mobil[position].durasi,mobil[position].total,mobil[position].date,mobil[position].month,mobil[position].year);fflush(stdin);
						                                    fclose(fp);
						                                    printf("\nData telah berhasil ditambahkan!\n");
						                                    printf("Tekan apapun untuk lanjut. . .");
						                                    
						
						                                    
															return 0;
														case 2: 
															printf("\nTransaksi Dibatalkan");															
															return 0;
													}
												}while(jawaban!=2); break;
										
										} 
										
                                        printf("Tekan apapun untuk lanjut. . .");
                                        getchar();
                                        break;
                                    default:
                                        printf("Pilihan Salah!\n"); getchar();
                                        break;
                                }
                            }
                            break;

                        case 2 : //cari mobil
                            stop=false;
                            while(stop==false)
                            {
                                system("cls");
                                search();
                                printf("Pilih : "); scanf("%d", &pilihCari); fflush(stdin);

                                switch(pilihCari)
                                {
                                    case 0 : // kembali
                                        system("cls");
                                        stop =true;
                                        break;
                                    case 1 : // cari dengan id
                                        searchAdv();
                                        printf("ID mobil yang dicari :");
                                        scanf("%d", &id);fflush(stdin);

                                        position=-1;
                                        position = sequentialSearchID(id, counter); // memanggil fungsi searching dengan id
                                        if(position != -1){ // jika data ditemukan
                                            printf("\n");
                                            printf("ID                  : %d\n", mobil[position].id);
                                            printf("Nama                : %s\n", mobil[position].nama);
                                            printf("Status              : %s\n", mobil[position].status);
                                            printf("Lokasi              : %s\n", mobil[position].lokasi);
                                            printf("Kota                : %s\n", mobil[position].kota);
                                            printf("Tahun               : %d\n", mobil[position].tahun);
                                            printf("Kapasitas           : %s\n", mobil[position].kapasitas);
                                            printf("Harga               : Rp %d,-\n", mobil[position].harga);
                                  		    }
                                        else
										{ // jika data tidak ditemukan
                                            printf("Data tidak ditemukan dengan ID %d", id);
                                        }
                                        
                                        printf("\nTekan apapun untuk lanjut. . .");
                                        getchar();
                                        break;
                                    case 2 : // cari dengan nama
                                        searchAdv();
                                        printf("Nama Mobil yang dicari : ");
                                        scanf("%[^\n]", &nama);fflush(stdin);

                                        position = -1;
                                        position = sequentialSearchNama(nama, counter); // memanggil fungsi searching dengan nama
                                        if(position != -1){ // jika data ditemukan
                                            printf("\n");
                                            printf("ID          : %d\n", mobil[position].id);
                                            printf("Nama        : %s\n", mobil[position].nama);
                                            printf("Status      : %s\n", mobil[position].status);
                                            printf("Lokasi      : %s\n", mobil[position].lokasi);
                                            printf("Kota        : %s\n", mobil[position].kota);
                                            printf("Tahun       : %d\n", mobil[position].tahun);
                                            printf("Kapasitas   : %s\n", mobil[position].kapasitas);
                                            printf("Harga       : Rp %d,-\n", mobil[position].harga);
                                        }
                                        else{ // jika data tidak ditemukan
                                            printf("Data tidak ditemukan dengan kata kunci %s", nama);
                                        }

                                        printf("\nTekan apapun untuk lanjut. . .");
                                        getchar();
                                        break;
                                    case 3 : // cari dengan status
                                        searchAdv();

                                        printf("Status mobil yang dicari : ");
                                        scanf("%[^\n]", &status);fflush(stdin);

                                        sequentialSearchStatus(status, counter,&jumlah); // memanggil fungsi searching dengan status


                                        if(jumlah==0){ // jika data tidak ditemukan
                                            printf("Anda salah memasukkan status.\n\n");
                                        }
                                        else{ // jika data ditemukan
                                            printf("Jumlah mobil dengan status \"%s\" : %d Mobil\n",status,jumlah);
                                        }

                                        printf("\nTekan apapun untuk lanjut. . .");
                                        getchar();
                                        break;
                                     case 4 : // cari dengan harga
                                        searchAdv();

                                        printf("Harga maximal mobil yang dicari : ");
                                        scanf("%d", &harga);fflush(stdin);

                                        sequentialSearchHarga(harga, counter,&jumlah); // memanggil fungsi searching dengan harga maksimal

                                        printf("Jumlah mobil dengan harga dibawah hingga %d : %d Mobil\n",harga,jumlah);
                                        printf("\nTekan apapun untuk lanjut. . .");
                                        getchar();
                                        break;
                                    case 5 : // cari dengan tahun
                                        searchAdv();

                                        printf("Tahun minimal mobil yang dicari : ");
                                        scanf("%d", &tahun);fflush(stdin);

                                        sequentialSearchtahun(tahun, counter,&jumlah);  // memanggil fungsi searching dengan tahun minimal

                                        printf("Jumlah mobil dengan tahun setara atau diatas %d : %d Mobil\n",tahun,jumlah);
                                        printf("\nTekan apapun untuk lanjut. . .");
                                        getchar();
                                        break;
                                    
                                }
                            }
                            break;
                            
                        case 3 ://Tampil sewa                                              
						stop=false;
                        sewaan();
                        while(stop==false)
						{
							// membaca data dari awal agar dapat digunakan berikutnya
							counter = 0;
							fp = fopen("datasewacar.txt", "r");
							while(!feof(fp))
							{
							fscanf(fp, "%[^#]#%d#%[^#]#%[^#]#%[^#]#%[^#]#%d#%[^#]#%d#%d#%d#%d#%d#%d\n",&mobil[position].usernames,&mobil[position].id, &mobil[position].nama, &mobil[position].status, &mobil[position].lokasi,&mobil[position].kota,&mobil[position].tahun,&mobil[position].kapasitas,&mobil[position].harga
							,&mobil[position].durasi,&mobil[position].total,&mobil[position].date,&mobil[position].month,&mobil[position].year);fflush(stdin);
							node = (struct data*) malloc(sizeof(struct data));
                            node -> next= NULL;

                            if(head==NULL)// head mobilong
                            {
                              head= node;
                            }
                            else{
                              now = head;
                              while(now->next!=NULL)
							  {
                                now = now->next;
                              }
                              now->next= node;
                              }
                              
								 
									printf("Username	    : %s\n", mobil[position].usernames);
			                        printf("ID                  : %d\n", mobil[position].id);
			                        printf("Nama                : %s\n", mobil[position].nama);
			                        printf("Status              : %s\n", mobil[position].status);
			                        printf("Lokasi              : %s\n", mobil[position].lokasi);
			                        printf("Kota                : %s\n", mobil[position].kota);
			                        printf("Tahun               : %d\n", mobil[position].tahun);
			                        printf("Kapasitas           : %s\n", mobil[position].kapasitas);
			                        printf("Harga               : Rp %d,-\n", mobil[position].harga);
			                        printf("Tanggal             : %d/%d/%d\n", mobil[position].date,mobil[position].month,mobil[position].year);
			                        printf("Durasi	            : %d\n", mobil[position].durasi);
			                        printf("Total		    : Rp %d,-\n", mobil[position].total);
			                        garis();
			                        
			                        counter++;
		                     
		                        
							}fclose(fp);
							system("pause");
							return 0;        
		                    }
							
                   		
				
						
                        case 4: // tambah mobil
                            stop=false;
                            while(stop==false){
                                system("cls");
                                tambahmobil();
                                printf("Username     : "); scanf("%s", &username); fflush(stdin);
                                printf("Password     : "); //scanf("%s", &password); fflush(stdin);

                                char c=' ';
                                int ctr=0;
                                while(ctr<=20){
                                    password[ctr]=getch();
                                    c=password[ctr];
                                    if(c==13) break;
                                    else printf("*");
                                    ctr++;
                                }
                                password[ctr]='\0';
                                ctr = 0;

                                if(strcmpi(username,"admin")==0 && strcmpi(password,"umn")==0 ){ // jika username dan password yang dimasukkan sesuai
                                    tambahmobil();

                                    printf("Nama                  :  "); scanf("%[^\n]",&nama);fflush(stdin);
                                    printf("Status                :  "); scanf("%[^\n]",&status);fflush(stdin);
                                    printf("Lokasi                :  "); scanf("%[^\n]",&lokasi);fflush(stdin);
                                    printf("Kota                  :  "); scanf("%[^\n]",&kota);fflush(stdin);
                                    printf("Tahun                 :  "); scanf("%d",&tahun);fflush(stdin);
                                    printf("Kapasitas             :  "); scanf("%[^\n]",&kapasitas);fflush(stdin);
                                    printf("Harga                 :  "); scanf("%d",&harga);fflush(stdin);


                                    // fungsi agar id mobil yang baru tidak sama dengan dataset sebelumnya
                                    id = 0;
                                    check = false;
                                    while(check ==false){
                                        for(i = 0; i < counter; i++){
                                            if(mobil[i].id == id){
                                                id ++;
                                                check = false;
                                                break;
                                            }else{
                                                check = true;
                                            }
                                        }
                                    }
                                    printf("Mobil ini mempunyai ID  : %d\n",id);

                                    //masukkan data ke txt
                                    fp = fopen("datacar.txt", "a+");
                                    fprintf(fp, "%d#%s#%s#%s#%s#%d#%s#%d\n", id, nama, status, lokasi,kota,tahun,kapasitas,harga);fflush(stdin);
                                    fclose(fp);
                                    printf("Data telah berhasil ditambahkan!\n");
                                    printf("Tekan apapun untuk lanjut. . .");
                                    getchar();

                                    // membaca data dari awal lagi agar dapat digunakan berikutnya
                                    counter = 0;
                                    fp = fopen("datacar.txt", "a+");
                                    while(!feof(fp)){
                                        fscanf(fp, "%d#%[^#]#%[^#]#%[^#]#%[^#]#%d#%[^#]#%d\n", &id, &nama, &status, &lokasi,&kota,&tahun,&kapasitas,&harga);fflush(stdin);
                                        node = (struct data*) malloc(sizeof(struct data));
                                        node -> next= NULL;

                                        if(head==NULL)// head mobilong
                                        {
                                          head= node;
                                        }
                                        else{
                                          now = head;
                                          while(now->next!=NULL){
                                            now = now->next;
                                          }
                                          now->next= node;
                                        }

                                        //Simpan data untuk sorting
                                        node->id = id;
                                        node->tahun = tahun;
                                        node->harga = harga;
                                        strcpy(node->nama, nama);
                                        strcpy(node->status, status);
                                        strcpy(node->lokasi, lokasi);
                                        strcpy(node->kota, kota);
                                        strcpy(node->kapasitas, kapasitas);

                                        //Semua Wilayah
                                        treeid=insertToTreeSortID(treeid,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
                                        treenama=insertToTreeSortNama(treenama,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
                                        treestatus=insertToTreeSortStatus(treestatus,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
                                        treelokasi=insertToTreeSortLokasi(treelokasi,id,tahun,harga,nama,status,lokasi,kota,kapasitas);

                                        //Depok
                                        treeiddepok=insertToTreeSortIDdepok(treeiddepok,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
                                        treenamadepok=insertToTreeSortNamadepok(treenamadepok,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
                                        treestatusdepok=insertToTreeSortStatusdepok(treestatusdepok,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
                                        treelokasidepok=insertToTreeSortLokasidepok(treelokasidepok,id,tahun,harga,nama,status,lokasi,kota,kapasitas);

                                        //Bogor
                                        treeidbogor=insertToTreeSortIDbogor(treeidbogor,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
                                        treestatusbogor=insertToTreeSortStatusbogor(treestatusbogor,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
                                        treenamabogor=insertToTreeSortNamabogor(treenamabogor,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
                                        treelokasibogor=insertToTreeSortLokasibogor(treelokasibogor,id,tahun,harga,nama,status,lokasi,kota,kapasitas);

                                        //Jakarta
                                        treeidjakarta=insertToTreeSortIDjakarta(treeidjakarta,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
                                        treenamajakarta=insertToTreeSortNamajakarta(treenamajakarta,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
                                        treestatusjakarta=insertToTreeSortStatusjakarta(treestatusjakarta,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
                                        treelokasijakarta=insertToTreeSortLokasijakarta(treelokasijakarta,id,tahun,harga,nama,status,lokasi,kota,kapasitas);

                                        //Bekasi
                                        treeidbekasi=insertToTreeSortIDbekasi(treeidbekasi,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
                                        treenamabekasi=insertToTreeSortNamabekasi(treenamabekasi,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
                                        treestatusbekasi=insertToTreeSortStatusbekasi(treestatusbekasi,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
                                        treelokasibekasi=insertToTreeSortLokasibekasi(treelokasibekasi,id,tahun,harga,nama,status,lokasi,kota,kapasitas);

                                        //Tangerang
                                        treeidtangerang=insertToTreeSortIDtangerang(treeidtangerang,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
                                        treenamatangerang=insertToTreeSortNamatangerang(treenamatangerang,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
                                        treestatustangerang=insertToTreeSortStatustangerang(treestatustangerang,id,tahun,harga,nama,status,lokasi,kota,kapasitas);
                                        treelokasitangerang=insertToTreeSortLokasitangerang(treelokasitangerang,id,tahun,harga,nama,status,lokasi,kota,kapasitas);


                                        //Simpan data untuk searching
                                        mobil[counter].id = id;
                                        mobil[counter].tahun = tahun;
                                        mobil[counter].harga = harga;
                                        strcpy(mobil[counter].nama, nama);
                                        strcpy(mobil[counter].status, status);
                                        strcpy(mobil[counter].lokasi, lokasi);
                                        strcpy(mobil[counter].kota, kota);
                                        strcpy(mobil[counter].kapasitas, kapasitas);

                                        counter++;
                                    }
                                    fclose(fp);

                                    stop=true;
                                }
                                else{  // jika username atau password yang dimasukkan salah
                                    printf("Maaf, password salah!\n");
                                    printf("Jika ingin menambahkan mobil, harap menghubungi admin via email (cs@mobilgalaxy.com)\n");
                                    printf("Kembali ke menu sebelumnya ? Ketik 'Ya' jika ingin. Jika tidak, ketik sembarang kata."); scanf("%s",&admin);fflush(stdin);
                                    if(strcmpi(admin,"Ya")==0)
									{
                                        stop = true;
                                    }
                                }

                            }
                        break;

                        default:
                            printf("Pilihan Salah!\n"); getchar();
                            break;
                    }
                }
            break;
            default:
                printf("Pilihan Salah\n");system("pause");
            break;
        }
    }
}
