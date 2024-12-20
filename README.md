# Banking System (C Program)

This is a simple banking system written in C that allows you to manage accounts and perform basic banking operations like deposit, withdrawal, transfer, account creation, deletion, and modification. The program uses a command-line interface for user interaction.

## Features

- **Account Management**:
  - Add new accounts
  - Delete accounts
  - Modify existing account details (account number and balance)

- **Banking Operations**:
  - Withdrawal from an account
  - Deposit into an account
  - Transfer between two accounts

- **Transaction History**:
  - Keep track of all operations performed on the accounts (like withdrawal, deposit, and transfer).

## Structure

The program is structured into two main parts:
- **Account Management**: Functions for adding, deleting, and modifying accounts.
- **Banking Operations**: Functions for performing transactions like withdrawals, deposits, and transfers.

## Data Structures

### `compte`
This structure holds the details of a bank account:
- `numero`: Account number (integer)
- `solde`: Account balance (float)

### `operation`
This structure holds the details of a banking operation:
- `type_op`: Type of operation (string)
- `etat`: State of operation (string)
- `montant`: Amount involved in the operation (float)
- `main`: Main account number (integer)
- `aux`: Auxiliary account number (integer, used for transfers)

## Functions

### Account Management
- `ajout()`: Adds a new account to the system.
- `recherche(int numero_cmpt)`: Searches for an account by its number.
- `supprime(int numero)`: Deletes an account by its number.
- `modification(int numero)`: Modifies the details of an existing account.

### Banking Operations
- `RETRAIT(int numero, float montant)`: Withdraws money from an account.
- `DEPOT(int numero, float montant)`: Deposits money into an account.
- `TRANSFERT(int numero1, int numero2, float montant)`: Transfers money from one account to another.

## Usage

1. **Compile the Program**:
   - Use any C compiler to compile the program:
     ```bash
     gcc -o banking_system banking_system.c
     ```

2. **Run the Program**:
   - After compiling, you can run the program with:
     ```bash
     ./banking_system
     ```

3. **Select an Operation**:
   - The program will display a menu with the following options:
     1. Withdrawal
     2. Deposit
     3. Transfer
     4. Add an Account
     5. Delete an Account
     6. Modify an Account
     7. Exit

   - Follow the prompts to perform the selected operation.

## Example

```bash
--- MENU ---
0: Retrait
1: Dépôt
2: Transfert
3: Ajout de compte
4: Suppression de compte
5: Modification de compte
6: Quitter
Votre choix: 3
Donner le numero de compte: 12345
Donner le solde: 500.00
Compte ajouté avec succès !

