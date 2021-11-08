/*
	Aluno: Gabriel da Silva Inácio
	Curso: Análise e Desenvolvimento de Sistemas
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIVROS "Livros.dat"
#define AUTOR "Autor.dat"
#define CATEGORIA "Categoria.dat"
#define EDITORA "Editora.dat"

//Define a struct do registro do arquivo de livros
struct reg_livro{
  int codigo, autor, codCategoria, codEditora, edicao, publicado, estoque;
  char titulo[50];
  float preco;  
};
//Define a struct do registro do arquivo de autor
struct reg_autor{
  int codigo;
  char nome[60], sobrenome[60];  
  
};
//Define a struct do registro do arquivo de categoria
struct reg_categoria{
 int codigo;
 char descricao[30];  
};
//Define a struct do registro do arquivo de editora
struct reg_editora{
  int codigo;
  char nome[60], contato[30], email[60];  
  int fone;
};

void cadastrarLivro(){
  FILE *fplivro;
  struct reg_livro livro;
  char op;  

  printf("\n>>> Cadastro de Livro:");
  printf("\n\nDigite o Codigo: ");
  fflush(stdin); scanf("%i",&livro.codigo);
  printf("Digite o Titulo: ");
  fflush(stdin); gets(livro.titulo);
  printf("Digite o Preco: ");
  fflush(stdin); scanf("%f",&livro.preco);
  printf("Digite codigo do autor:  ");  
  fflush(stdin); scanf("%i",&livro.autor);
  printf("Digite o codigo da categoria: ");
  fflush(stdin); scanf("%i",&livro.codCategoria);
  printf("Digite o codigo da editora: ");
  fflush(stdin); scanf("%i",&livro.codEditora);
  printf("Digite o numero da edicao: ");
  fflush(stdin); scanf("%i",&livro.edicao);
  printf("Digite a quantidade em estoque: ");
  fflush(stdin); scanf("%i",&livro.estoque);
  printf("Digite o ano de publicacao: ");
  fflush(stdin); scanf("%i",&livro.publicado);  
 
 
  printf("\nSalvar Livro?(S/N) ");
  fflush(stdin); scanf("%c",&op);  

  if ((op=='s')||(op=='S')){ //Confirmou - Gravar Livro no Arquivo
    //Abrir o Arquivo
    fplivro = fopen("Livros.dat","ab"); //Abre com "a" para adicionar no fim do arquivo

    //Gravar o registro do Livro no Arquivo
    fwrite(&livro,sizeof(livro),1,fplivro);

    //Fechar o Arquivo
    fclose(fplivro);

    printf("\nLivro Salvo com Sucesso.");
  }
  else{
    printf("\nOperacao Cancelada!");
  }
}//Fim cadastrarLivro()

void cadastrarAutor(){	
  FILE *fpautor;
  struct reg_autor autor;
  char op;

  printf("\n>>> Cadastro de autor:");
  printf("\n\nDigite o Codigo: ");
  fflush(stdin); scanf("%i",&autor.codigo);
  printf("\n\nDigite o Nome: ");
  fflush(stdin); gets(autor.nome);  
  printf("\n\nDigite o Sobrenome: ");
  fflush(stdin); gets(autor.sobrenome);  

  printf("\nSalvar Autor?(S/N) ");
  fflush(stdin); scanf("%c",&op);

  if ((op=='s')||(op=='S')){ //Confirmou - Gravar autor no Arquivo
    //Abrir o Arquivo
    fpautor = fopen("Autor.dat","ab"); //Abre com "a" para adicionar no fim do arquivo

    //Gravar o registro do autor no Arquivo
    fwrite(&autor,sizeof(autor),1,fpautor);

    //Fechar o Arquivo
    fclose(fpautor);

    printf("\nautor Salvo com Sucesso.");
  }
  else{
    printf("\nOperacao Cancelada!");
  }
}//Fim cadastrarAutor()

void cadastrarCategoria(){
  FILE *fpcategoria;
  struct reg_categoria categoria;
  char op;

  printf("\n>>> Cadastro de Categoria:");
  printf("\n\nDigite o Codigo: ");
  fflush(stdin); scanf("%i",&categoria.codigo);
  printf("\n\nDigite a Descricao: ");
  fflush(stdin); gets(categoria.descricao);  
  
  printf("\nSalvar Categoria?(S/N) ");
  fflush(stdin); scanf("%c",&op);

  if ((op=='s')||(op=='S')){ //Confirmou - Gravar categoria no Arquivo
    //Abrir o Arquivo
    fpcategoria = fopen("Categoria.dat","ab"); //Abre com "a" para adicionar no fim do arquivo

    //Gravar o registro da categoria no Arquivo
    fwrite(&categoria,sizeof(categoria),1,fpcategoria);

    //Fechar o Arquivo
    fclose(fpcategoria);

    printf("\ncategoria Salvo com Sucesso.");
  }
  else{
    printf("\nOperacao Cancelada!");
  }
}//Fim cadastrarCategoria()

void cadastrarEditora(){
  FILE *fpeditora;
  struct reg_editora editora;
  char op;

  printf("\n>>> Cadastro de editora:");
  printf("\n\nDigite o Codigo: ");
  fflush(stdin); scanf("%i",&editora.codigo);
  printf("\n\nDigite o Nome: ");
  fflush(stdin); gets(editora.nome);  
  printf("\n\nDigite o Contato: ");
  fflush(stdin); gets(editora.contato);  
  printf("\n\nDigite o Email: ");
  fflush(stdin); gets(editora.email);  
  printf("\n\nDigite o Telefone: ");
  fflush(stdin); scanf("%i",&editora.fone);
  
  printf("\nSalvar Editora?(S/N) ");
  fflush(stdin); scanf("%c",&op);

  if ((op=='s')||(op=='S')){ //Confirmou - Gravar editora no Arquivo
    //Abrir o Arquivo
    fpeditora = fopen("Editora.dat","ab"); //Abre com "a" para adicionar no fim do arquivo

    //Gravar o registro da editora no Arquivo
    fwrite(&editora,sizeof(editora),1,fpeditora);

    //Fechar o Arquivo
    fclose(fpeditora);

    printf("\neditora Salvo com Sucesso.");
  }
  else{
    printf("\nOperacao Cancelada!");
  }
}//Fim cadastrarEditora()

void listarTodosLivros(){
  FILE *fplivro;  
  struct reg_livro livro;         
  
  if ((fplivro = fopen(LIVROS,"rb"))==NULL){
    printf("\nErro na Abertura do Arquivo!!");
    return;
  }      
 
   printf("\n          Lista de Todas as Editoras");
   printf("\nCodigo  Titulo                         autor           Categoria       Editora         Edicao          Publicado       Estoque    Preco");
  //Ler os registros e exibir na Tela
  while (fread(&livro,sizeof(livro),1,fplivro)==1){        	  	
    printf("\n%-6i  %-30s %-15i %-15i %-15i %-15i %-15i %-10i %5.2f",livro.codigo, livro.titulo,livro.autor,livro.codCategoria,livro.codEditora,livro.edicao,livro.publicado,livro.estoque,livro.preco);
  }

  //Fechar o Arquivo
  fclose(fplivro);  
        

}//Fim listarTodosLivros()

void relatorioLivrosCategoria(){
  FILE *fplivro;  
  struct reg_livro livro;  
  
  FILE *fpeditora;  
  struct reg_editora editora;    
  
  FILE *fpcategoria;  
  struct reg_categoria categoria;  
  
  FILE *fpautor;  
  struct reg_autor autor;  
  char tit[50];
  
   printf("\nInforme o nome da  categoria: ");
   fflush(stdin); gets(tit);
  
  if ((fplivro = fopen(LIVROS,"rb"))==NULL){
    printf("\nErro na Abertura do Arquivo!!");
    return;
  }      
  fpautor = fopen(AUTOR,"rb");
  fpcategoria = fopen(CATEGORIA,"rb");
  fpeditora = fopen(EDITORA,"rb");  
  
    
  
  
 
  	 printf("\n          Relatorio de Livros por Categoria");
  printf("\nCodigo  Titulo                         autor           Categoria       Editora         Edicao          Publicado       Estoque    Preco");
  //Ler os registros e exibir na Tela
  while (fread(&livro,sizeof(livro),1,fplivro)==1){ 
    fread(&autor,sizeof(autor),1,fpautor);
    fread(&categoria,sizeof(categoria),1,fpcategoria);
    fread(&editora,sizeof(editora),1,fpeditora);  
    if(strcmp(categoria.descricao,tit)==0){    	
    	printf("\n%-6i  %-30s %-15s %-15s %-15s %-15i %-15i %-10i %5.2f",livro.codigo, livro.titulo,autor.nome,categoria.descricao,editora.nome,livro.edicao,livro.publicado,livro.estoque,livro.preco);
	}
    
  }
  
  

  //Fechar o Arquivo
  fclose(fplivro);  
  fclose(fpautor); 
  fclose(fpcategoria); 
  fclose(fpeditora); 

}//Fim relatorioLivrosCategoria()

void relatorioLivrosEstoqueAbaixo(){ 
  FILE *fplivro;  
  struct reg_livro livro; 
  
  FILE *fpeditora;  
  struct reg_editora editora;    
  
  FILE *fpcategoria;  
  struct reg_categoria categoria;  
  
  FILE *fpautor;  
  struct reg_autor autor;    
  int cod;
  //Abrir o Arquivo
  if ((fplivro = fopen(LIVROS,"rb"))==NULL){
    printf("\nErro na Abertura do Arquivo!!");
    return;
  }
  fpautor = fopen(AUTOR,"rb");
  fpcategoria = fopen(CATEGORIA,"rb");
  fpeditora = fopen(EDITORA,"rb");
    
     
  	 printf("\n          Relatorio de Livros com estoque abaixo de 5");
  printf("\nCodigo  Titulo                         autor           Categoria       Editora         Edicao          Publicado       Estoque    Preco");
  //Ler os registros e exibir na Tela
  while (fread(&livro,sizeof(livro),1,fplivro)==1){
  	fread(&autor,sizeof(autor),1,fpautor);
    fread(&categoria,sizeof(categoria),1,fpcategoria);
    fread(&editora,sizeof(editora),1,fpeditora);
  	 if(livro.estoque <5){  	    	 	     	
       printf("\n%-6i  %-30s %-15s %-15s %-15s %-15i %-15i %-10i %5.2f",livro.codigo, livro.titulo,autor.nome,categoria.descricao,editora.nome,livro.edicao,livro.publicado,livro.estoque,livro.preco);	       
     }
  }
  
  

  //Fechar o Arquivo
  fclose(fplivro);  
  fclose(fpautor); 
  fclose(fpcategoria); 
  fclose(fpeditora); 

}//Fim relatorioLivrosEstoqueAbaixo()

void consultarLivroCodigo(){
  FILE *fplivro;  
  struct reg_livro livro;  
  
  FILE *fpeditora;  
  struct reg_editora editora;    
  
  FILE *fpcategoria;  
  struct reg_categoria categoria;  
  
  FILE *fpautor;  
  struct reg_autor autor;  
  int cod;
  
	printf("\nInforme o codigo do livro: ");
  	fflush(stdin); scanf("%i",&cod);
  
  //Abrir o Arquivo
  if ((fplivro = fopen(LIVROS,"rb"))==NULL){
    printf("\nErro na Abertura do Arquivo!!");
    return;
  }
  fpautor = fopen(AUTOR,"rb");
  fpcategoria = fopen(CATEGORIA,"rb");
  fpeditora = fopen(EDITORA,"rb");  
  
 
  	 printf("\n          Consulta do livro pelo codigo"); 
  while (fread(&livro,sizeof(livro),1,fplivro)==1){   
     if(livro.codigo == cod){
     	fread(&autor,sizeof(autor),1,fpautor);
    	fread(&categoria,sizeof(categoria),1,fpcategoria);
    	fread(&editora,sizeof(editora),1,fpeditora);
       	printf("\nCodigo:%i",livro.codigo);
       	printf("\nTitulo:%s",livro.titulo);
       	printf("\nAutor:%s %s",autor.nome, autor.sobrenome);
       	printf("\nCategoria:%s",categoria.descricao);
       	printf("\nEditora:%s",editora.nome);
       	printf("\nEdicao:%i",livro.edicao);
       	printf("\nPublicado:%i",livro.publicado);
       	printf("\nEstoque:%i",livro.estoque);
       	printf("\nPreco:%5.2f",livro.preco);       
     }	  	
  } 
  
     
	   	  
  //Fechar o Arquivo
  fclose(fplivro);  
  fclose(fpautor); 
  fclose(fpcategoria); 
  fclose(fpeditora); 
  
  return;
  
     
}//Fim consultarLivroCodigo()

void consultarLivroTitulo(){
  FILE *fplivro;  
  struct reg_livro livro;  
  
  FILE *fpeditora;  
  struct reg_editora editora;    
  
  FILE *fpcategoria;  
  struct reg_categoria categoria;  
  
  FILE *fpautor;  
  struct reg_autor autor;
  char tit[50]; 


  //Solicitar o Titulo do Livro a ser Localizado
  printf("\nDigite o Titulo do Livro a ser Localizado: ");
  fflush(stdin); gets(tit);

  //Localizar o Livro
  //Abrir o Arquivo
  if ((fplivro = fopen(LIVROS,"rb"))==NULL){
    printf("\nErro na Abertura do Arquivo!!");
    return;
  }
	fpautor = fopen(AUTOR,"rb");
  fpcategoria = fopen(CATEGORIA,"rb");
  fpeditora = fopen(EDITORA,"rb");
  
  while((fread(&livro,sizeof(livro),1,fplivro)==1)){
    if (strcmp(livro.titulo,tit)==0){ //Achei o Livro
      	fread(&autor,sizeof(autor),1,fpautor);
    	fread(&categoria,sizeof(categoria),1,fpcategoria);
    	fread(&editora,sizeof(editora),1,fpeditora);
       	printf("\nCodigo:%i",livro.codigo);
       	printf("\nTitulo:%s",livro.titulo);
       	printf("\nAutor:%s %s",autor.nome, autor.sobrenome);
       	printf("\nCategoria:%s",categoria.descricao);
       	printf("\nEditora:%s",editora.nome);
       	printf("\nEdicao:%i",livro.edicao);
       	printf("\nPublicado:%i",livro.publicado);
       	printf("\nEstoque:%i",livro.estoque);
       	printf("\nPreco:%5.2f",livro.preco);            
    }
  }

  //Fechar o Arquivo
  fclose(fplivro);  
  fclose(fpautor); 
  fclose(fpcategoria); 
  fclose(fpeditora); 
  
  return;

}//Fim consultarLivroTitulo()

void consultarLivroPalavraChaveTitulo(){
  FILE *fplivro;  
  struct reg_livro livro;  
  
  FILE *fpeditora;  
  struct reg_editora editora;    
  
  FILE *fpcategoria;  
  struct reg_categoria categoria;  
  
  FILE *fpautor;  
  struct reg_autor autor;
  char palavra[40];
  int achou;


  //Solicitar o Titulo do Livro a ser Localizado
  printf("\nDigite o Palavra Chave: ");
  fflush(stdin); gets(palavra);

  //Localizar o Livro
  //Abrir o Arquivo
  if ((fplivro = fopen(LIVROS,"rb"))==NULL){
    printf("\nErro na Abertura do Arquivo!!");
    return;
  }
	
	fpautor = fopen(AUTOR,"rb");
	fpcategoria = fopen(CATEGORIA,"rb");
	fpeditora = fopen(EDITORA,"rb");  
  while((fread(&livro,sizeof(livro),1,fplivro))==1){
    if (strstr(livro.titulo,palavra)!=NULL){ //Achei o Livro
    
      	fread(&autor,sizeof(autor),1,fpautor);
    	fread(&categoria,sizeof(categoria),1,fpcategoria);
    	fread(&editora,sizeof(editora),1,fpeditora);
       	printf("\nCodigo:%i",livro.codigo);
       	printf("\nTitulo:%s",livro.titulo);
       	printf("\nAutor:%s %s",autor.nome, autor.sobrenome);
       	printf("\nCategoria:%s",categoria.descricao);
       	printf("\nEditora:%s",editora.nome);
       	printf("\nEdicao:%i",livro.edicao);
       	printf("\nPublicado:%i",livro.publicado);
       	printf("\nEstoque:%i",livro.estoque);
       	printf("\nPreco:%5.2f",livro.preco);         
    }
  }

   //Fechar o Arquivo
  fclose(fplivro);  
  fclose(fpautor); 
  fclose(fpcategoria); 
  fclose(fpeditora); 
  
  return;
 

}//Fim consultarLivroPalavraChaveTitulo()

void excluirLivro(){
FILE *fplivro, *fplivronew;
struct reg_livro livro;
int cod, achou;
char op;

  //Localizar o Livro a ser Excluído
  printf("\nDigite o Codigo do Livro a ser Excluido: ");
  fflush(stdin); scanf("%i",&cod);

  //Localizar o Livro
  //Abrir o Arquivo binário (b) para leitura (r)
  if ((fplivro = fopen(LIVROS,"rb"))==NULL){
    printf("\nErro na Abertura do Arquivo!!");
    return;
  }

  achou = 0;
  while((achou==0)&&((fread(&livro,sizeof(livro),1,fplivro))==1)){
    if (livro.codigo==cod){ //Achei o Livro
      printf("\nCodigo: %i",livro.codigo);
      printf("\nTitulo: %s",livro.titulo);
      printf("\nPreco : %5.2f",livro.preco);
      achou = 1;
    }
  }
  fclose(fplivro);

  if (achou==0){
    printf("\nLivro NAO Localizado!");
    return;
  }

  //Pedir Confirmação
  printf("\nConfirma Exclusao?(S/N) ");
  fflush(stdin); scanf("%c",&op);
  if((op!='S')&&(op!='s')){ //Não Confirmou
    printf("\nOperacao Cancelada!");
    return;
  }

  //Se confirmou - Fazer a Exclusão Física
  fplivro = fopen(LIVROS,"rb");  //Arquivo original que contem o livro a ser excluído
  fplivronew = fopen("livrosnew.dat","wb");  //Novo arquivo que vai receber os livros

  while ((fread(&livro,sizeof(livro),1,fplivro))==1){
    if (livro.codigo!=cod){ //Se o livro for diferente do livro a ser removido
      fwrite(&livro,sizeof(livro),1,fplivronew); //Grava no novo arquivo
    }
  }
  fclose(fplivro);
  fclose(fplivronew);
  system("del Livros.dat");  //Deleta o arquivo antigo
  system("ren livrosnew.dat Livros.dat");  //Renomeia o novo arquivo
  printf("\nLivro excluido com Sucesso.");

}//Fim excluirLivro()

void relatorioLivrosAutor(){
  FILE *fplivro;  
  struct reg_livro livro;  
  
  FILE *fpeditora;  
  struct reg_editora editora;    
  
  FILE *fpcategoria;  
  struct reg_categoria categoria;  
  
  FILE *fpautor;  
  struct reg_autor autor;  
  char tit[50];  
  
  printf("\nInforme o codigo do autor: ");
  fflush(stdin); gets(tit);
  
  //Abrir o Arquivo
  if ((fplivro = fopen(LIVROS,"rb"))==NULL){
    printf("\nErro na Abertura do Arquivo!!");
    return;
  }
  fpautor = fopen(AUTOR,"rb");
  fpcategoria = fopen(CATEGORIA,"rb");
  fpeditora = fopen(EDITORA,"rb");  
  
 
  	 printf("\n          Relatorio de Livros do Autor");
  printf("\nCodigo  Titulo                         autor           Categoria       Editora         Edicao          Publicado       Estoque    Preco");
  while (fread(&livro,sizeof(livro),1,fplivro)==1){     	  	
  		fread(&autor,sizeof(autor),1,fpautor);
    	fread(&categoria,sizeof(categoria),1,fpcategoria);
    	fread(&editora,sizeof(editora),1,fpeditora);
     if(strcmp(autor.nome,tit)==0){     	     	
       printf("\n%-6i  %-30s %-15s %-15s %-15s %-15i %-15i %-10i %5.2f",livro.codigo, livro.titulo,autor.nome,categoria.descricao,editora.nome,livro.edicao,livro.publicado,livro.estoque,livro.preco);      
	 }	  	
  } 
  
  

  ///Fechar o Arquivo
  fclose(fplivro);  
  fclose(fpautor); 
  fclose(fpcategoria); 
  fclose(fpeditora); 

}//Fim relatorioLivrosAutor()

void listarTodasEditora(){
  FILE *fpeditora;  
  struct reg_editora editora;         
  
  if ((fpeditora = fopen(EDITORA,"rb"))==NULL){
    printf("\nErro na Abertura do Arquivo!!");
    return;
  }      
 
   printf("\n          Lista de Todas as Editoras");
  printf("\nCodigo   nome                           Contato         Email                             Fone");
  //Ler os registros e exibir na Tela
  while (fread(&editora,sizeof(editora),1,fpeditora)==1){        	  	
    printf("\n%-8i %-30s %-15s %-33s %i", editora.codigo, editora.nome, editora.contato, editora.email, editora.fone);
  }

  //Fechar o Arquivo
  fclose(fpeditora);  
  
      
 

}//Fim listarTodasEditora()

void listarTodasCategoria(){
  FILE *fpcategoria;  
  struct reg_categoria categoria;         
  
  if ((fpcategoria = fopen(CATEGORIA,"rb"))==NULL){
    printf("\nErro na Abertura do Arquivo!!");
    return;
  }      
 
   printf("\n          Lista de Todas as Categoria");
  printf("\nCodigo   Descricao");
  //Ler os registros e exibir na Tela
  while (fread(&categoria,sizeof(categoria),1,fpcategoria)==1){        	  	
    printf("\n%-8i %s", categoria.codigo, categoria.descricao);
  }

  //Fechar o Arquivo
  fclose(fpcategoria);  

}//Fim listarTodasCategoria()

void listarTodasAutor(){
  FILE *fpautor;  
  struct reg_autor autor;         
  
  if ((fpautor = fopen(AUTOR,"rb"))==NULL){
    printf("\nErro na Abertura do Arquivo!!");
    return;
  }      
 
   printf("\n          Lista de Todas os Autores");
  printf("\nCodigo   Nome            Sobrenome");
  //Ler os registros e exibir na Tela
  while (fread(&autor,sizeof(autor),1,fpautor)==1){        	  	
    printf("\n%-8i %-15s %s", autor.codigo, autor.nome, autor.sobrenome);
  }

  //Fechar o Arquivo
  fclose(fpautor);  

}//Fim listarTodasAutor()

main(){
  int op;

  do{
  printf("\n\n####################################################");
    printf("\n##         Livraria 1byte                         ##");
    printf("\n##                                                ##");
    printf("\n## 1) Cadastrar Livro                             ##");    
    printf("\n## 1.1(111)) Cadastrar autor                      ##");  
    printf("\n## 1.2(122)) Cadastrar categoria                  ##");
    printf("\n## 1.3(133)) Cadastrar editora                    ##");
    printf("\n## 2) Listar Todos os Livros                      ##"); 
	printf("\n## 3) Listar todas as editoras                    ##");	
	printf("\n## 4) Listar todas as categorias                  ##");
	printf("\n## 5) Listar todas os autores                     ##");        
    printf("\n## 6) Consultar pelo Codigo do Livro              ##");
    printf("\n## 7) Consultar pelo Titulo do Livro              ##");
    printf("\n## 8) Consultar Palavra Chave no Titulo do Livro  ##");
	printf("\n## 9) Relatorio de Livros por categoria           ##");   
	printf("\n## 10) Relatorio de Livros com estoque abaixo de5 ##");  
	printf("\n## 11) Relatorio de Livros de um autor            ##"); 	   
    printf("\n## 12) Excluir um Livro                           ##");	
    printf("\n## 0) Sair                                        ##");

    printf("\nOpcao-> ");
    fflush(stdin); scanf("%i",&op);

    switch (op){
    case 1: //Cadastrar Livro
      cadastrarLivro();
      break;   
    case 2: //Listar todos os Livros
      listarTodosLivros();
      break; 
	case 3: //listar todas as editoras
	  listarTodasEditora();
	  break;    
	case 4: //listar todas as categorias
	  listarTodasCategoria();
	  break;
	case 5: //listar todos os autores
	  listarTodasAutor();
	  break;
	case 6: //consultar pelo codigo do livro
	  consultarLivroCodigo();
	  break;
	case 7: //consultar pelo titulo do livro
	  consultarLivroTitulo();
	  break;
	case 8: //consultar palavra chave do titulo
	  consultarLivroPalavraChaveTitulo();
	  break;
	case 9: //relatoria do livros por categoria
	  relatorioLivrosCategoria();
	  break;
	case 10: //relatoria do livros por estoque abaixo de x
	  relatorioLivrosEstoqueAbaixo();
	  break;
	case 11: //relatoria do livros por autor
	  relatorioLivrosAutor();
	  break;
	case 12: //excluir
	  excluirLivro();
	  break;
	case 111: //cadastrar autor
	  cadastrarAutor();
	  break;
	case 122: //cadastrar categoria
	  cadastrarCategoria();
	  break;
	case 133: //cadastrar editora
	  cadastrarEditora();
	  break;
	}
	  


  }while(op!=0);
}




