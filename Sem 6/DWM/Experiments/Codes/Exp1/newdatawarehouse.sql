CREATE TABLE dimspectator(
	spectator_id SERIAL PRIMARY KEY,
	spectator_name VARCHAR(30),
	status VARCHAR(50),
	phone_number NUMERIC(10),
    address VARCHAR(100)
);

INSERT INTO dimspectator(spectator_name,status,phone_number,address)VALUES
('Fiyori Elias','student',6434732623,'90,Reisenoir 45710 Madridejos'),
('Ulrike Reiniger','student',03784688370,'120,Via Scuderlando
64010-Civitella Del Tronto TE'),
('Guilherme Cunha Cavalcanti','teacher',0892585793,'41 Daly Terrace CURRAMBINE WA 6028'),
('Galina Kudryashova','teacher',7063664327,'99 Withers Close, ALLGREAVE,SK11 5HH'),
('Isao Toyota','student',78310125,'107 Rue Echikh Mohamed Abbes
6172 EL BARRAMA');

CREATE TABLE dimdate(
	date_id SERIAL PRIMARY KEY,
	day_entry VARCHAR(50),
	month_entry NUMERIC(10),
    quarter_entry NUMERIC(10),
    year_entry NUMERIC(10)
);

INSERT INTO dimdate
	(day_entry, month_entry, quarter_entry, year_entry)
VALUES
	('Monday',03,2,2018),
	('Tuesday',10,3,2019),
	('Wednesday',09,4,2020),
	('Friday',04,1,2018),
    ('Sunday',11,2,2017);

CREATE TABLE dimgame(
	game_id SERIAL PRIMARY KEY,
	game_name VARCHAR(10),
	game_description VARCHAR(20),
	game_producer VARCHAR(20)
);
INSERT INTO dimgame(
	game_name,game_description,game_producer
)
VALUES
	('Cricket','bat and ball','ICC'),
	('Football','contact','FIFA'),
	('Hockey','bat and ball','FILA'),
	('Sprint','Track and Field','IOC')

create table dimlocation (
	location_id SERIAL PRIMARY KEY,
	location_name VARCHAR(50),
	phone_number VARCHAR(50),
	street_name VARCHAR(50),
	city_name VARCHAR(50),
	state_name VARCHAR(50)
);

insert into dimlocation (location_id, location_name, phone_number, street_name, city_name, state_name) values (1, '10921 Chinook Drive', '+1 646 842 0458', 'Birchwood', 'New York City', 'New York');
insert into dimlocation (location_id, location_name, phone_number, street_name, city_name, state_name) values (2, '401 Corry Road', '+1 917 600 6796', 'Blackbird', 'Flushing', 'New York');
insert into dimlocation (location_id, location_name, phone_number, street_name, city_name, state_name) values (3, '55 Beilfuss Way', '+1 205 631 7075', 'Hazelcrest', 'Birmingham', 'Alabama');
insert into dimlocation (location_id, location_name, phone_number, street_name, city_name, state_name) values (4, '00199 Shasta Way', '+1 312 114 2826', 'Express', 'Aurora', 'Illinois');
insert into dimlocation (location_id, location_name, phone_number, street_name, city_name, state_name) values (5, '5 Texas Road', '+1 913 620 1338', 'Evergreen', 'Shawnee Mission', 'Kansas');

CREATE TABLE factgame_fare(
	spectator_id SERIAL REFERENCES spectator(spectator_id),
	date_id SERIAL REFERENCES datetable(date_id),
	game_id SERIAL REFERENCES game_table(game_id),
	location_id SERIAL REFERENCES location_table(location_id),
	count_entry INT,
	charge INT
);
INSERT INTO factgame_fare(count_entry,charge)
VALUES
    (1000,20000),
    (2000,40000),
    (3000,60000),
    (4000,70000),
    (5000,90000);
