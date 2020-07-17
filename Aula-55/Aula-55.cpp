#include <iostream>  
#include <string.h>
#include <stdlib.h>

// Deletando todos valores da lista 


struct Elementos{
	 
	  int dado;
	  Elementos *seguinte;
	
	};
	
	

Elementos *lista = NULL;


using namespace std;

void menu();
void inserirValorLista(Elementos *&, int);
void exibirValorLista(Elementos *);
void buscarValorLista(Elementos *, int);
void eleminarValorLista(Elementos *&, int);
void eliminarTodaLista(Elementos *&, int &);



int main(){
	
	menu();
	 
	return 0;
		
	}


// Menu
void menu(){
	
	int opcao, num;
 	
	do{
		cout<<"Menu -  Selecione a opção desejada abaixo:  "<<endl;
		cout<<"1. Inserir um valor: "<<endl;
		cout<<"2. Exibir um valor: "<<endl;
		cout<<"3. Buscar um valor: "<<endl;
		cout<<"4. Deletar um  valor: "<<endl;
		cout<<"5. Deletar a lista: "<<endl;
		cout<<"6. Sair: "<<endl;
		
		cout<<"Informe a opção desejada:  ";
		cin>>opcao;
		
		switch(opcao){
			
			case 1: 
			      
			    cout<<"Informe um valor para adicionar na lista: ";
				cin>> num;
				
				inserirValorLista(lista, num);
				
				cout<<endl<<endl;
				system("pause");
				break;
			    
			    
			break;    	
			
			case 2: exibirValorLista(lista);
			
			    cout<<"\n";
				system("pause");
				
			break;
			
			
			case 3: cout<<" Informe o valor que voce deseja encontar:  ";
			        cin>>num;
			        
				    buscarValorLista(lista, num);	
			    
			    
			    
			        cout<<endl<<endl;;
				    system("pause");
				
			break;
			
			case 4: cout<<" Informe o valor que voce deseja deletar:  ";
			        cin>>num;
			        
				    eleminarValorLista(lista, num);
				    		    
			        cout<<endl<<endl;
				    system("pause");
				
			break;
			
			case 5: 
			      
			      while(lista != NULL){
					  
					  eliminarTodaLista(lista, num);
					 
					  cout<<num<<"  ---  ";
					  
					  }
			
			cout<<endl;
			system("pause");	
			break;
			
				
							
			}
			
			system("cls");
		
			
		}while(opcao != 6);
	
	
	
	
	}
	
// Inserir valor na lista
void inserirValorLista(Elementos *&lista, int n){
	
	  Elementos *novo_elemento = new Elementos();
	  
	  novo_elemento -> dado = n;
	  
	  Elementos *aux1 = lista;
	  Elementos *aux2; 
	  
	  while((aux1 != NULL) && (aux1-> dado < n)){
		  
		    aux2 = aux1;
		    aux1 = aux1->seguinte; 
		   		  	  
		  }
	    
	    // inserir no inicio da lista
	    if(lista == aux1){ 
			
			  lista = novo_elemento;
			
			}else{
				// valor uqe a gente for inserir for maios que o proximo valor
				aux2->seguinte = novo_elemento;
				
				
				}
				
			novo_elemento->seguinte = aux1;
			cout<<endl;
			cout<<" valor : " << n << "  adiciconado com secesso"<<endl;	
	
	
	}


// Exibir valores na lista
void exibirValorLista(Elementos *lista){
	  
	   
	   Elementos *elementoAtual = new Elementos();
	   
	   elementoAtual = lista;
	   
	   while(elementoAtual != NULL){
		   
		     //Ebindo valores
		  
		     cout<< elementoAtual->dado << "   --->>>  ";
		     elementoAtual = elementoAtual->seguinte;
		   
		   
		   }
	  	
	}
	
	
//buscar valor na lista
void buscarValorLista(Elementos *lista, int n){
	
	   Elementos *elementoAtual = new Elementos();
	   
	   bool achou = false;
	   
	   elementoAtual = lista;
	   
	   while((elementoAtual != NULL) && (elementoAtual->dado <= n)){
		     
		     if(elementoAtual -> dado == n){ 
				 
				    achou = true;
				 
				 
				 }
				 
				 
				 elementoAtual = elementoAtual -> seguinte;
		       
		   
		   }
		   
		   if(achou == true){
			   
			     cout<< "Valor:   "<< n << "  encontrado com sucesso"<<endl;
			    
			   
			   }else{
			     
			      cout<<"Valor:  "<< n << " naõ foi encontrado "<<endl;
			   
			   }
	   
	
	}	


// Deletar um valor
void eleminarValorLista(Elementos *&lista, int n){
	
	  //verificar se a lista esa vazia
	  if(lista != NULL){
		   
		    Elementos *aux_delete = NULL;
		    Elementos *anterior = NULL;  //1 2 3
		    
		    aux_delete = lista;
		    
		    // percorrer a lista
		    while((aux_delete != NULL) && (aux_delete->dado != n)){
				  
				   anterior = aux_delete;
				   aux_delete = aux_delete->seguinte;
				  
				
				}
		    
		    //Não encontrar valor
		    if(aux_delete == NULL){
				  cout<<endl;
				  cout<< " Não encontramos o valor informado"<<endl;
				
				}else if(anterior == NULL){
					
					 // eliminado o prieiro valor 1 2
					 
					 lista = lista->seguinte;
					 delete aux_delete;
					
					
					} else{
		                 
		                 // eleemento ele está na lista mais este elemento não é o primeiro valor
		  
		                anterior->seguinte =aux_delete ->seguinte; // 1 2   3
		                delete aux_delete;
		  
					  
			  
			        }
	
	     }
	}



// Deletar todos os valores da lista
void eliminarTodaLista(Elementos *&lista, int &n){
	 
	   Elementos *aux = lista; // 1 ->  2 ->  3 ->  4
	   n = aux->dado; // 1  2 
	   lista = aux->seguinte;
	   delete aux;
	
	}





