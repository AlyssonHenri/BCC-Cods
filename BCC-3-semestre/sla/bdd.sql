----------- 1º
{ F.NomeFilme | FornecedorFilme(F) ∧
∃ FD (Fornecedor(FD) ∧ FD.FornecedorID = F.FornecedorID ∧
FD.Nome = 'Walt Disney Pictures') ∨
∃ FW (Fornecedor(FW) ∧ FW.FornecedorID = F.FornecedorID ∧
FW.Nome = 'Warner Bros Pictures') }

----------- 2º
{F.Nome | Fornecedor(F) ∧
∀ FF (FornecedorFilme(FF) ∨ 
∃ FM (Filmes(FM) ∧ 
FM.FilmeID = FF.FilmeID ∧ 
FM.NomeFilme ≠ '%Harry Potter%'))}

----------- 3º
{ F.NomeFilme | Filme(F) ∧
∃ A (Aluguel(A) ∧ A.FilmeID = F.FilmeID ∧
∀ B (Aluguel(B) ∧ A.Duracao ≥ B.Duracao)) }

----------- 4º
{ C.Nome, C.Sobrenome | Cliente(C) ∧
∀ FD (Filmes(FD) ∧ FD.NomeFilme = "Walt Disney Pictures" →
∃ P (Pedido(P) ∧ P.FilmeID = FD.FilmeID ∧
P.ClienteID = C.ClienteID)) }

----------- 5º
{ F.NomeFilme | Filme(F) ∧ 
∃ P ∃ A1 ∃ A2( Pedido(P) ∧  Aluguel(A1) ∧  Aluguel(A2) ∧ 
P.FilmeID = F.FilmeID ∧ 
A1.PedidoID = P.PedidoID ∧ 
A2.PedidoID = P.PedidoID ∧ 
A1 ≠ A2) }

----------- 6º
{ C | Cliente(C) ∧ 
∃ A ∃ F(Aluguel(A) ∧ Filme(F) ∧ 
F.FilmeID = A.FilmeID ∧ 
F.Nome = '%Vingadores%') ∨ 
∃ A ∃ F ∃ FF( Aluguel(A) ∧ Filme(F) ∧ FornecedorFilme(FF) ∧ 
F.FilmeID = A.FilmeID ∧
FF.FilmeID = F.FilmeID ∧ 
∃ FR ( Fornecedor(FR) ∧ FR.FornecedorID = FF.FornecedorID ∧ 
FR.Nome = 'Universal Studios')) }

----------- 7º
{ F.NomeFilme | Filme(F) ∧ 
∃ I1 E I2( Inventario(I1) ∧ Inventario(I2) ∧ 
I1.FilmeID = F.FilmeID ∧ 
I2.FilmeID = F.FilmeID ∧ 
I1.PedidoID ≠ I2.PedidoID) }

----------- 8º
{ C.Nome, C.Sobrenome | Cliente(C) ∧ 
∃ A (Aluguel(A) ∧ 
A.ClienteID = C.ClienteID ∧ 
A.Duracao >= 5) }

----------- 9º
{ F.Nome | Fornecedor(F), Filmes(X), FornecedorFilme(FF), Filmes(Y), FornecedorFilme(FF'') ∧ 
X.FilmeID = FF.FilmeID ∧
X.NomeFilme = '%X-Men%' ∧ 
Y.FilmeID = FF''.FilmeID ∧
Y.NomeFilme = '%X-Men%' ∧
FF.Preco <= FF''.Preco }

----------- 10º
{ F.NomeFilme | Filmes(F), Inventario(I) ∧ ¬(F.FilmeID = I.FilmeID) }