using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0412_계좌실습
{
    delegate void AccountEvent(object obj, AccountEventArgs e);

    class AccountManager
    {
        public event AccountEvent AccountEventHandler = null;
        public event AccountEvent DepositEventHandler = null;
        public event AccountEvent WithdrawEventHandler = null;
        public event AccountEvent SelectEventHandler = null;
        public event AccountEvent TransferEventHandler = null;
        public event AccountEvent SelectNameEventHandler = null;
        public Dictionary<int, PAccount> accounts = new Dictionary<int, PAccount>();
        static public AccountManager Singleton { get; private set; }


        static AccountManager()
        {
            Singleton = new AccountManager(); 
        }

        private AccountManager() { }

        
        //계좌 생성
        internal bool AddAccount(int id, string name, int balance, int idx)
        {
            if(idx ==1)
            {
                PAccount paccount = new Account(id, name, balance);
                accounts.Add(paccount.Id, paccount);
            }
            else if(idx == 2)
            {
                PAccount paccount = new FaithAccount(id, name, balance);
                accounts.Add(paccount.Id, paccount);
            }
            else if(idx ==3)
            {
                PAccount paccount = new ContriAccount(id, name, balance);
                accounts.Add(paccount.Id, paccount);
            }
            if(accounts.ContainsKey(id))
            {
                return false;
            }

            //accounts[account.Name] = account;

            // 이벤트 핸들러가 등록되어 있을 때
            if (AccountEventHandler != null)
            {
                AccountEventHandler(this, new AccountEventArgs(accounts[id]));

            }
            return true;
        }

        //입금
        internal bool Deposit(int id, int balance)
        {
            if (accounts.ContainsKey(id))
            {
                accounts[id].AddMoney(balance);


                // 이벤트 핸들러가 등록되어 있을 때
                if (DepositEventHandler != null)
                {
                    DepositEventHandler(this, new AccountEventArgs(accounts[id]));
                }

                return true;
            }
            else
            {
                return false;
            }
            
        }

        internal bool Selectnameprint(string name)
        {
            PAccount account;

            foreach (KeyValuePair<int, PAccount> item in accounts)
            {
                if (item.Value.Name == name)
                {
                    account = item.Value;

                    if (accounts.ContainsKey(account.Id))
                    {
                        // 이벤트 핸들러가 등록되어 있을 때
                        if (SelectEventHandler != null)
                        {
                            SelectNameEventHandler(this, new AccountEventArgs(accounts[account.Id]));
                        }
                    }
                }
                else
                {
                    return false;
                }
            }
            return true;
        }

        internal bool Transfer(int id, int id2, int balance)
        {
            if (accounts.ContainsKey(id) && accounts.ContainsKey(id2))
            {
                accounts[id].SubMoney(balance);
                accounts[id2].AddMoney(balance);


                // 이벤트 핸들러가 등록되어 있을 때
                if (TransferEventHandler != null)
                {
                    TransferEventHandler(this, new AccountEventArgs(accounts[id]));
                }

                return true;
            }
            else
            {
                if(accounts.ContainsKey(id) ==false)
                {
                    throw new Exception(id+"정보가 존재하지 않습니다.");
                }
                else if (accounts.ContainsKey(id2) == false)
                {
                    throw new Exception(id2 + "정보가 존재하지 않습니다.");
                }
                return false;
            }
        }
        
        //선택출력
        internal bool Selectprint(int id)
        {
            if (accounts.ContainsKey(id))
            {
                // 이벤트 핸들러가 등록되어 있을 때
                if (SelectEventHandler != null)
                {
                    SelectEventHandler(this, new AccountEventArgs(accounts[id]));
                }

                return true;
            }
            else
            {
                return false;
            }
        }

        //출금
        internal bool Withdraw(int id, int balance)
        {
            if (accounts.ContainsKey(id))
            {
                accounts[id].SubMoney(balance);


                // 이벤트 핸들러가 등록되어 있을 때
                if (WithdrawEventHandler != null)
                {
                    WithdrawEventHandler(this, new AccountEventArgs(accounts[id]));
                }

                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
