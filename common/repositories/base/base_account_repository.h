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

#ifndef EQEMU_BASE_ACCOUNT_REPOSITORY_H
#define EQEMU_BASE_ACCOUNT_REPOSITORY_H

#include "../../database.h"
#include "../../strings.h"
#include <ctime>

class BaseAccountRepository {
public:
	struct Account {
		int         id;
		std::string name;
		std::string charname;
		int         sharedplat;
		std::string password;
		int         status;
		std::string ls_id;
		int         lsaccount_id;
		int         gmspeed;
		int         revoked;
		int         karma;
		std::string minilogin_ip;
		int         hideme;
		int         rulesflag;
		time_t      suspendeduntil;
		int         time_creation;
		int         expansion;
		std::string ban_reason;
		std::string suspend_reason;
		std::string crc_eqgame;
		std::string crc_skillcaps;
		std::string crc_basedata;
	};

	static std::string PrimaryKey()
	{
		return std::string("id");
	}

	static std::vector<std::string> Columns()
	{
		return {
			"id",
			"name",
			"charname",
			"sharedplat",
			"password",
			"status",
			"ls_id",
			"lsaccount_id",
			"gmspeed",
			"revoked",
			"karma",
			"minilogin_ip",
			"hideme",
			"rulesflag",
			"suspendeduntil",
			"time_creation",
			"expansion",
			"ban_reason",
			"suspend_reason",
			"crc_eqgame",
			"crc_skillcaps",
			"crc_basedata",
		};
	}

	static std::vector<std::string> SelectColumns()
	{
		return {
			"id",
			"name",
			"charname",
			"sharedplat",
			"password",
			"status",
			"ls_id",
			"lsaccount_id",
			"gmspeed",
			"revoked",
			"karma",
			"minilogin_ip",
			"hideme",
			"rulesflag",
			"UNIX_TIMESTAMP(suspendeduntil)",
			"time_creation",
			"expansion",
			"ban_reason",
			"suspend_reason",
			"crc_eqgame",
			"crc_skillcaps",
			"crc_basedata",
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
		return std::string("account");
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

	static Account NewEntity()
	{
		Account entry{};

		entry.id             = 0;
		entry.name           = "";
		entry.charname       = "";
		entry.sharedplat     = 0;
		entry.password       = "";
		entry.status         = 0;
		entry.ls_id          = "eqemu";
		entry.lsaccount_id   = 0;
		entry.gmspeed        = 0;
		entry.revoked        = 0;
		entry.karma          = 0;
		entry.minilogin_ip   = "";
		entry.hideme         = 0;
		entry.rulesflag      = 0;
		entry.suspendeduntil = 0;
		entry.time_creation  = 0;
		entry.expansion      = 0;
		entry.ban_reason     = "";
		entry.suspend_reason = "";
		entry.crc_eqgame     = "";
		entry.crc_skillcaps  = "";
		entry.crc_basedata   = "";

		return entry;
	}

	static Account GetAccountEntry(
		const std::vector<Account> &accounts,
		int account_id
	)
	{
		for (auto &account : accounts) {
			if (account.id == account_id) {
				return account;
			}
		}

		return NewEntity();
	}

	static Account FindOne(
		Database& db,
		int account_id
	)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"{} WHERE id = {} LIMIT 1",
				BaseSelect(),
				account_id
			)
		);

		auto row = results.begin();
		if (results.RowCount() == 1) {
			Account entry{};

			entry.id             = atoi(row[0]);
			entry.name           = row[1] ? row[1] : "";
			entry.charname       = row[2] ? row[2] : "";
			entry.sharedplat     = atoi(row[3]);
			entry.password       = row[4] ? row[4] : "";
			entry.status         = atoi(row[5]);
			entry.ls_id          = row[6] ? row[6] : "";
			entry.lsaccount_id   = atoi(row[7]);
			entry.gmspeed        = atoi(row[8]);
			entry.revoked        = atoi(row[9]);
			entry.karma          = atoi(row[10]);
			entry.minilogin_ip   = row[11] ? row[11] : "";
			entry.hideme         = atoi(row[12]);
			entry.rulesflag      = atoi(row[13]);
			entry.suspendeduntil = strtoll(row[14] ? row[14] : "-1", nullptr, 10);
			entry.time_creation  = atoi(row[15]);
			entry.expansion      = atoi(row[16]);
			entry.ban_reason     = row[17] ? row[17] : "";
			entry.suspend_reason = row[18] ? row[18] : "";
			entry.crc_eqgame     = row[19] ? row[19] : "";
			entry.crc_skillcaps  = row[20] ? row[20] : "";
			entry.crc_basedata   = row[21] ? row[21] : "";

			return entry;
		}

		return NewEntity();
	}

	static int DeleteOne(
		Database& db,
		int account_id
	)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"DELETE FROM {} WHERE {} = {}",
				TableName(),
				PrimaryKey(),
				account_id
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static int UpdateOne(
		Database& db,
		Account account_entry
	)
	{
		std::vector<std::string> update_values;

		auto columns = Columns();

		update_values.push_back(columns[1] + " = '" + Strings::Escape(account_entry.name) + "'");
		update_values.push_back(columns[2] + " = '" + Strings::Escape(account_entry.charname) + "'");
		update_values.push_back(columns[3] + " = " + std::to_string(account_entry.sharedplat));
		update_values.push_back(columns[4] + " = '" + Strings::Escape(account_entry.password) + "'");
		update_values.push_back(columns[5] + " = " + std::to_string(account_entry.status));
		update_values.push_back(columns[6] + " = '" + Strings::Escape(account_entry.ls_id) + "'");
		update_values.push_back(columns[7] + " = " + std::to_string(account_entry.lsaccount_id));
		update_values.push_back(columns[8] + " = " + std::to_string(account_entry.gmspeed));
		update_values.push_back(columns[9] + " = " + std::to_string(account_entry.revoked));
		update_values.push_back(columns[10] + " = " + std::to_string(account_entry.karma));
		update_values.push_back(columns[11] + " = '" + Strings::Escape(account_entry.minilogin_ip) + "'");
		update_values.push_back(columns[12] + " = " + std::to_string(account_entry.hideme));
		update_values.push_back(columns[13] + " = " + std::to_string(account_entry.rulesflag));
		update_values.push_back(columns[14] + " = FROM_UNIXTIME(" + (account_entry.suspendeduntil > 0 ? std::to_string(account_entry.suspendeduntil) : "null") + ")");
		update_values.push_back(columns[15] + " = " + std::to_string(account_entry.time_creation));
		update_values.push_back(columns[16] + " = " + std::to_string(account_entry.expansion));
		update_values.push_back(columns[17] + " = '" + Strings::Escape(account_entry.ban_reason) + "'");
		update_values.push_back(columns[18] + " = '" + Strings::Escape(account_entry.suspend_reason) + "'");
		update_values.push_back(columns[19] + " = '" + Strings::Escape(account_entry.crc_eqgame) + "'");
		update_values.push_back(columns[20] + " = '" + Strings::Escape(account_entry.crc_skillcaps) + "'");
		update_values.push_back(columns[21] + " = '" + Strings::Escape(account_entry.crc_basedata) + "'");

		auto results = db.QueryDatabase(
			fmt::format(
				"UPDATE {} SET {} WHERE {} = {}",
				TableName(),
				Strings::Implode(", ", update_values),
				PrimaryKey(),
				account_entry.id
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static Account InsertOne(
		Database& db,
		Account account_entry
	)
	{
		std::vector<std::string> insert_values;

		insert_values.push_back(std::to_string(account_entry.id));
		insert_values.push_back("'" + Strings::Escape(account_entry.name) + "'");
		insert_values.push_back("'" + Strings::Escape(account_entry.charname) + "'");
		insert_values.push_back(std::to_string(account_entry.sharedplat));
		insert_values.push_back("'" + Strings::Escape(account_entry.password) + "'");
		insert_values.push_back(std::to_string(account_entry.status));
		insert_values.push_back("'" + Strings::Escape(account_entry.ls_id) + "'");
		insert_values.push_back(std::to_string(account_entry.lsaccount_id));
		insert_values.push_back(std::to_string(account_entry.gmspeed));
		insert_values.push_back(std::to_string(account_entry.revoked));
		insert_values.push_back(std::to_string(account_entry.karma));
		insert_values.push_back("'" + Strings::Escape(account_entry.minilogin_ip) + "'");
		insert_values.push_back(std::to_string(account_entry.hideme));
		insert_values.push_back(std::to_string(account_entry.rulesflag));
		insert_values.push_back("FROM_UNIXTIME(" + (account_entry.suspendeduntil > 0 ? std::to_string(account_entry.suspendeduntil) : "null") + ")");
		insert_values.push_back(std::to_string(account_entry.time_creation));
		insert_values.push_back(std::to_string(account_entry.expansion));
		insert_values.push_back("'" + Strings::Escape(account_entry.ban_reason) + "'");
		insert_values.push_back("'" + Strings::Escape(account_entry.suspend_reason) + "'");
		insert_values.push_back("'" + Strings::Escape(account_entry.crc_eqgame) + "'");
		insert_values.push_back("'" + Strings::Escape(account_entry.crc_skillcaps) + "'");
		insert_values.push_back("'" + Strings::Escape(account_entry.crc_basedata) + "'");

		auto results = db.QueryDatabase(
			fmt::format(
				"{} VALUES ({})",
				BaseInsert(),
				Strings::Implode(",", insert_values)
			)
		);

		if (results.Success()) {
			account_entry.id = results.LastInsertedID();
			return account_entry;
		}

		account_entry = NewEntity();

		return account_entry;
	}

	static int InsertMany(
		Database& db,
		std::vector<Account> account_entries
	)
	{
		std::vector<std::string> insert_chunks;

		for (auto &account_entry: account_entries) {
			std::vector<std::string> insert_values;

			insert_values.push_back(std::to_string(account_entry.id));
			insert_values.push_back("'" + Strings::Escape(account_entry.name) + "'");
			insert_values.push_back("'" + Strings::Escape(account_entry.charname) + "'");
			insert_values.push_back(std::to_string(account_entry.sharedplat));
			insert_values.push_back("'" + Strings::Escape(account_entry.password) + "'");
			insert_values.push_back(std::to_string(account_entry.status));
			insert_values.push_back("'" + Strings::Escape(account_entry.ls_id) + "'");
			insert_values.push_back(std::to_string(account_entry.lsaccount_id));
			insert_values.push_back(std::to_string(account_entry.gmspeed));
			insert_values.push_back(std::to_string(account_entry.revoked));
			insert_values.push_back(std::to_string(account_entry.karma));
			insert_values.push_back("'" + Strings::Escape(account_entry.minilogin_ip) + "'");
			insert_values.push_back(std::to_string(account_entry.hideme));
			insert_values.push_back(std::to_string(account_entry.rulesflag));
			insert_values.push_back("FROM_UNIXTIME(" + (account_entry.suspendeduntil > 0 ? std::to_string(account_entry.suspendeduntil) : "null") + ")");
			insert_values.push_back(std::to_string(account_entry.time_creation));
			insert_values.push_back(std::to_string(account_entry.expansion));
			insert_values.push_back("'" + Strings::Escape(account_entry.ban_reason) + "'");
			insert_values.push_back("'" + Strings::Escape(account_entry.suspend_reason) + "'");
			insert_values.push_back("'" + Strings::Escape(account_entry.crc_eqgame) + "'");
			insert_values.push_back("'" + Strings::Escape(account_entry.crc_skillcaps) + "'");
			insert_values.push_back("'" + Strings::Escape(account_entry.crc_basedata) + "'");

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

	static std::vector<Account> All(Database& db)
	{
		std::vector<Account> all_entries;

		auto results = db.QueryDatabase(
			fmt::format(
				"{}",
				BaseSelect()
			)
		);

		all_entries.reserve(results.RowCount());

		for (auto row = results.begin(); row != results.end(); ++row) {
			Account entry{};

			entry.id             = atoi(row[0]);
			entry.name           = row[1] ? row[1] : "";
			entry.charname       = row[2] ? row[2] : "";
			entry.sharedplat     = atoi(row[3]);
			entry.password       = row[4] ? row[4] : "";
			entry.status         = atoi(row[5]);
			entry.ls_id          = row[6] ? row[6] : "";
			entry.lsaccount_id   = atoi(row[7]);
			entry.gmspeed        = atoi(row[8]);
			entry.revoked        = atoi(row[9]);
			entry.karma          = atoi(row[10]);
			entry.minilogin_ip   = row[11] ? row[11] : "";
			entry.hideme         = atoi(row[12]);
			entry.rulesflag      = atoi(row[13]);
			entry.suspendeduntil = strtoll(row[14] ? row[14] : "-1", nullptr, 10);
			entry.time_creation  = atoi(row[15]);
			entry.expansion      = atoi(row[16]);
			entry.ban_reason     = row[17] ? row[17] : "";
			entry.suspend_reason = row[18] ? row[18] : "";
			entry.crc_eqgame     = row[19] ? row[19] : "";
			entry.crc_skillcaps  = row[20] ? row[20] : "";
			entry.crc_basedata   = row[21] ? row[21] : "";

			all_entries.push_back(entry);
		}

		return all_entries;
	}

	static std::vector<Account> GetWhere(Database& db, std::string where_filter)
	{
		std::vector<Account> all_entries;

		auto results = db.QueryDatabase(
			fmt::format(
				"{} WHERE {}",
				BaseSelect(),
				where_filter
			)
		);

		all_entries.reserve(results.RowCount());

		for (auto row = results.begin(); row != results.end(); ++row) {
			Account entry{};

			entry.id             = atoi(row[0]);
			entry.name           = row[1] ? row[1] : "";
			entry.charname       = row[2] ? row[2] : "";
			entry.sharedplat     = atoi(row[3]);
			entry.password       = row[4] ? row[4] : "";
			entry.status         = atoi(row[5]);
			entry.ls_id          = row[6] ? row[6] : "";
			entry.lsaccount_id   = atoi(row[7]);
			entry.gmspeed        = atoi(row[8]);
			entry.revoked        = atoi(row[9]);
			entry.karma          = atoi(row[10]);
			entry.minilogin_ip   = row[11] ? row[11] : "";
			entry.hideme         = atoi(row[12]);
			entry.rulesflag      = atoi(row[13]);
			entry.suspendeduntil = strtoll(row[14] ? row[14] : "-1", nullptr, 10);
			entry.time_creation  = atoi(row[15]);
			entry.expansion      = atoi(row[16]);
			entry.ban_reason     = row[17] ? row[17] : "";
			entry.suspend_reason = row[18] ? row[18] : "";
			entry.crc_eqgame     = row[19] ? row[19] : "";
			entry.crc_skillcaps  = row[20] ? row[20] : "";
			entry.crc_basedata   = row[21] ? row[21] : "";

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

#endif //EQEMU_BASE_ACCOUNT_REPOSITORY_H
