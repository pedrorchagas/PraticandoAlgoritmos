create table prb2615(
	id int,
	name varchar(100),
	street varchar(100),
	city varchar(100)
);

insert into prb2615 values
	(1,"Giovanna Goncalves Oliveira","Rua Mato Grosso","Canoas"),
    (2,	"Kauã Azevedo Ribeiro",	"Travessa Ibiá",	"Uberlândia"),
    (3,	"Rebeca Barbosa Santos",	"Rua Observatório Meteorológico",	"Salvador"),
    (4,	"Sarah Carvalho Correia",	"Rua Antônio Carlos da Silva",	"Uberlândia"),
    (5,	"João Almeida Lima",	"Rua Rio Taiuva",	"Ponta Grossa"),
    (6,	"Diogo Melo Dias",	"Rua Duzentos e Cinqüenta",	"Várzea Grande");


# resposta do exercício 
select distinct city from customers;