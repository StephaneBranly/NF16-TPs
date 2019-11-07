/* Structutre d'une Transaction */
typedef struct Transaction T_Transaction ;
struct Transaction{
    int idEtu;
    float montant;
    char* descr ;
    T_Transaction* succ;
};

/* Structure d'un bloc */
typedef struct Block T_Block ;
struct Block{
    int idBlock;
    int date;
    T_Transaction *T_TransactionJ;
    T_Block *succ;
};

typedef T_Block* BlockChain;

/* Fonction 1 */ T_Transaction *ajouterTransaction(int, float, char*, T_Transaction*);
/* Fonction 2 */ BlockChain ajouterBlock(BlockChain);
/* Fonction 3 */ float totalTransactionEtudiantBlock(int,T_Block);
/* Fonction 4 */ float soldeEtudiant(int, BlockChain);
/* Fonction 5 */ void crediter(int, float, char *, BlockChain);
/* Fonction 6 */ int payer(int, float, char *, BlockChain);
/* Fonction 7 */ void consulter(int, BlockChain);
/* Fonction 8 */ int transfert(int, int, float, char *, BlockChain);


/* MENU 2 */ void AfficherTransactionsBlock(T_Block);
            T_Block* RechercherBlock(int, T_Block*);
/* MENU 3 */ void AfficherTransactionEtudiantBlock(int, T_Block);
/* MENU 6 */ void payer_repas(int, BlockChain);

/* Fonction bonus */
void Afficher_Transaction(T_Transaction*);
void Tout_Afficher(BlockChain);
void Tout_Liberer(BlockChain);
int verif_ID(int);
