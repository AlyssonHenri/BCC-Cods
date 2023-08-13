CREATE TABLE items (
  	nome varchar(40) NOT NULL UNIQUE,
  	descricao varchar (10000) NOT NULL,
  	PRIMARY KEY (nome)
);

CREATE TABLE entidades (
  	nome varchar(40) NOT NULL UNIQUE,
  	PRIMARY KEY (nome)
);

CREATE TABLE spells (
	nome_spell VARCHAR(45) NOT NULL UNIQUE,
  	categoria VARCHAR (45) CHECK ( categoria = 'Sorceries' or categoria = 'Pyromancies' or categoria = 'Miracles') NOT NULL,
  	usos int NOT NULL, 
  	slots int NOT NULL,
  	int_req int NOT NULL,
  	fht_req int NOT NULL,
  	tipo VARCHAR(45) NOT NULL,
  	FOREIGN KEY (nome_spell) REFERENCES items (nome) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE monstro (
  	nome_monstro VARCHAR(45) NOT NULL UNIQUE,
  	r_fis VARCHAR(8) NOT NULL,
  	r_impacto VARCHAR(8) NOT NULL,
  	r_corte VARCHAR(8) NOT NULL,
  	r_perfurar VARCHAR(8) NOT NULL,
  	r_magic VARCHAR(8) NOT NULL,
  	r_fogo VARCHAR(8) NOT NULL,
  	r_electro VARCHAR(8) NOT NULL,
  	r_poison VARCHAR(1) NOT NULL,
  	r_toxic VARCHAR(1) NOT NULL,
  	r_bleed VARCHAR(1) NOT NULL,
	FOREIGN KEY (nome_monstro) REFERENCES entidades (nome) ON DELETE CASCADE ON UPDATE CASCADE
);