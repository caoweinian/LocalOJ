// parse and test the command arguments with ease

#ifndef ARGPARSE_H
#define ARGPARSE_H

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include "result.h"

namespace oj 
{
	class cmdarg
	{
	private:
		using Self = cmdarg;
	public:
		/* the big-five */
		cmdarg(const cmdarg&) = default;
		cmdarg(cmdarg&&) = default;
		cmdarg& operator=(const cmdarg&) = default;
		cmdarg& operator=(cmdarg&&) = default;
		~cmdarg() = default;

		/* construct a cmdarg using the arguments. Not responsible for 
		checking their validity */
		static Result<Self> from(int argc, const char** argv);
	
		/* get command */
		const std::string& command() const { return this->dm_command; }

		/* test if the argument package has some given property */
		bool has_property(char p) const
		{
			return any_of(begin(this->dm_properties),end(this->dm_properties),
			[&](char c){return c==p;});
		}

		/* test if the argument package has some given keyword */
		bool has_kv_key(const std::string& k) const
		{
			return this->dm_kvp.find(k) != this->dm_kvp.end();
		}

		/* get the exact argument via keyword */
		const std::string& get_kv_exact(const std::string& k) const
		{
			return this->dm_kvp.find(k)->second[0];
		}

		/* get the argument package via keyword */
		const std::vector<std::string>& get_kv_group(const std::string& k) const
		{
			return this->dm_kvp.find(k)->second;
		}

		/* shortcut for member get_kv_exact */
		const std::string& operator[](const std::string& k) const
		{
			return this->get_kv_exact(k);
		}

	private:
		cmdarg(std::string command,
			std::string properties,
			std::unordered_map<std::string, std::vector<std::string>> kvp);
	private:
		std::string dm_command;
		std::string dm_properties;
		std::unordered_map<std::string, std::vector<std::string>> dm_kvp;
	};
}

#endif // !ARGPARSE_H
