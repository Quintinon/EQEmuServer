/**
 * DO NOT MODIFY THIS FILE
 *
 * This repository was automatically generated and is NOT to be modified directly.
 * Any repository modifications are meant to be made to the repository extending the base.
 * Any modifications to base repositories are to be made by the generator only
 *
 * @generator ./utils/scripts/generators/repository-generator.pl
 * @docs https://eqemu.gitbook.io/server/in-development/developer-area/repositories
 */

#ifndef EQEMU_BASE_PETS_REPOSITORY_H
#define EQEMU_BASE_PETS_REPOSITORY_H

#include "../../database.h"
#include "../../strings.h"
#include <ctime>

class BasePetsRepository {
public:
	struct Pets {
		int         id;
		std::string type;
		int         petpower;
		int         npcID;
		int         temp;
		int         petcontrol;
		int         petnaming;
		int         monsterflag;
		int         equipmentset;
	};

	static std::string PrimaryKey()
	{
		return std::string("id");
	}

	static std::vector<std::string> Columns()
	{
		return {
			"id",
			"type",
			"petpower",
			"npcID",
			"temp",
			"petcontrol",
			"petnaming",
			"monsterflag",
			"equipmentset",
		};
	}

	static std::vector<std::string> SelectColumns()
	{
		return {
			"id",
			"type",
			"petpower",
			"npcID",
			"temp",
			"petcontrol",
			"petnaming",
			"monsterflag",
			"equipmentset",
		};
	}

	static std::string ColumnsRaw()
	{
		return std::string(Strings::Implode(", ", Columns()));
	}

	static std::string SelectColumnsRaw()
	{
		return std::string(Strings::Implode(", ", SelectColumns()));
	}

	static std::string TableName()
	{
		return std::string("pets");
	}

	static std::string BaseSelect()
	{
		return fmt::format(
			"SELECT {} FROM {}",
			SelectColumnsRaw(),
			TableName()
		);
	}

	static std::string BaseInsert()
	{
		return fmt::format(
			"INSERT INTO {} ({}) ",
			TableName(),
			ColumnsRaw()
		);
	}

	static Pets NewEntity()
	{
		Pets entry{};

		entry.id           = 0;
		entry.type         = "";
		entry.petpower     = 0;
		entry.npcID        = 0;
		entry.temp         = 0;
		entry.petcontrol   = 0;
		entry.petnaming    = 0;
		entry.monsterflag  = 0;
		entry.equipmentset = -1;

		return entry;
	}

	static Pets GetPetsEntry(
		const std::vector<Pets> &petss,
		int pets_id
	)
	{
		for (auto &pets : petss) {
			if (pets.id == pets_id) {
				return pets;
			}
		}

		return NewEntity();
	}

	static Pets FindOne(
		Database& db,
		int pets_id
	)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"{} WHERE id = {} LIMIT 1",
				BaseSelect(),
				pets_id
			)
		);

		auto row = results.begin();
		if (results.RowCount() == 1) {
			Pets entry{};

			entry.id           = atoi(row[0]);
			entry.type         = row[1] ? row[1] : "";
			entry.petpower     = atoi(row[2]);
			entry.npcID        = atoi(row[3]);
			entry.temp         = atoi(row[4]);
			entry.petcontrol   = atoi(row[5]);
			entry.petnaming    = atoi(row[6]);
			entry.monsterflag  = atoi(row[7]);
			entry.equipmentset = atoi(row[8]);

			return entry;
		}

		return NewEntity();
	}

	static int DeleteOne(
		Database& db,
		int pets_id
	)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"DELETE FROM {} WHERE {} = {}",
				TableName(),
				PrimaryKey(),
				pets_id
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static int UpdateOne(
		Database& db,
		Pets pets_entry
	)
	{
		std::vector<std::string> update_values;

		auto columns = Columns();

		update_values.push_back(columns[1] + " = '" + Strings::Escape(pets_entry.type) + "'");
		update_values.push_back(columns[2] + " = " + std::to_string(pets_entry.petpower));
		update_values.push_back(columns[3] + " = " + std::to_string(pets_entry.npcID));
		update_values.push_back(columns[4] + " = " + std::to_string(pets_entry.temp));
		update_values.push_back(columns[5] + " = " + std::to_string(pets_entry.petcontrol));
		update_values.push_back(columns[6] + " = " + std::to_string(pets_entry.petnaming));
		update_values.push_back(columns[7] + " = " + std::to_string(pets_entry.monsterflag));
		update_values.push_back(columns[8] + " = " + std::to_string(pets_entry.equipmentset));

		auto results = db.QueryDatabase(
			fmt::format(
				"UPDATE {} SET {} WHERE {} = {}",
				TableName(),
				Strings::Implode(", ", update_values),
				PrimaryKey(),
				pets_entry.id
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static Pets InsertOne(
		Database& db,
		Pets pets_entry
	)
	{
		std::vector<std::string> insert_values;

		insert_values.push_back(std::to_string(pets_entry.id));
		insert_values.push_back("'" + Strings::Escape(pets_entry.type) + "'");
		insert_values.push_back(std::to_string(pets_entry.petpower));
		insert_values.push_back(std::to_string(pets_entry.npcID));
		insert_values.push_back(std::to_string(pets_entry.temp));
		insert_values.push_back(std::to_string(pets_entry.petcontrol));
		insert_values.push_back(std::to_string(pets_entry.petnaming));
		insert_values.push_back(std::to_string(pets_entry.monsterflag));
		insert_values.push_back(std::to_string(pets_entry.equipmentset));

		auto results = db.QueryDatabase(
			fmt::format(
				"{} VALUES ({})",
				BaseInsert(),
				Strings::Implode(",", insert_values)
			)
		);

		if (results.Success()) {
			pets_entry.id = results.LastInsertedID();
			return pets_entry;
		}

		pets_entry = NewEntity();

		return pets_entry;
	}

	static int InsertMany(
		Database& db,
		std::vector<Pets> pets_entries
	)
	{
		std::vector<std::string> insert_chunks;

		for (auto &pets_entry: pets_entries) {
			std::vector<std::string> insert_values;

			insert_values.push_back(std::to_string(pets_entry.id));
			insert_values.push_back("'" + Strings::Escape(pets_entry.type) + "'");
			insert_values.push_back(std::to_string(pets_entry.petpower));
			insert_values.push_back(std::to_string(pets_entry.npcID));
			insert_values.push_back(std::to_string(pets_entry.temp));
			insert_values.push_back(std::to_string(pets_entry.petcontrol));
			insert_values.push_back(std::to_string(pets_entry.petnaming));
			insert_values.push_back(std::to_string(pets_entry.monsterflag));
			insert_values.push_back(std::to_string(pets_entry.equipmentset));

			insert_chunks.push_back("(" + Strings::Implode(",", insert_values) + ")");
		}

		std::vector<std::string> insert_values;

		auto results = db.QueryDatabase(
			fmt::format(
				"{} VALUES {}",
				BaseInsert(),
				Strings::Implode(",", insert_chunks)
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static std::vector<Pets> All(Database& db)
	{
		std::vector<Pets> all_entries;

		auto results = db.QueryDatabase(
			fmt::format(
				"{}",
				BaseSelect()
			)
		);

		all_entries.reserve(results.RowCount());

		for (auto row = results.begin(); row != results.end(); ++row) {
			Pets entry{};

			entry.id           = atoi(row[0]);
			entry.type         = row[1] ? row[1] : "";
			entry.petpower     = atoi(row[2]);
			entry.npcID        = atoi(row[3]);
			entry.temp         = atoi(row[4]);
			entry.petcontrol   = atoi(row[5]);
			entry.petnaming    = atoi(row[6]);
			entry.monsterflag  = atoi(row[7]);
			entry.equipmentset = atoi(row[8]);

			all_entries.push_back(entry);
		}

		return all_entries;
	}

	static std::vector<Pets> GetWhere(Database& db, std::string where_filter)
	{
		std::vector<Pets> all_entries;

		auto results = db.QueryDatabase(
			fmt::format(
				"{} WHERE {}",
				BaseSelect(),
				where_filter
			)
		);

		all_entries.reserve(results.RowCount());

		for (auto row = results.begin(); row != results.end(); ++row) {
			Pets entry{};

			entry.id           = atoi(row[0]);
			entry.type         = row[1] ? row[1] : "";
			entry.petpower     = atoi(row[2]);
			entry.npcID        = atoi(row[3]);
			entry.temp         = atoi(row[4]);
			entry.petcontrol   = atoi(row[5]);
			entry.petnaming    = atoi(row[6]);
			entry.monsterflag  = atoi(row[7]);
			entry.equipmentset = atoi(row[8]);

			all_entries.push_back(entry);
		}

		return all_entries;
	}

	static int DeleteWhere(Database& db, std::string where_filter)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"DELETE FROM {} WHERE {}",
				TableName(),
				where_filter
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static int Truncate(Database& db)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"TRUNCATE TABLE {}",
				TableName()
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

};

#endif //EQEMU_BASE_PETS_REPOSITORY_H
