#include<Components/JsonComponent.h>


struct jason_value : json_component
{
private:
	std::shared_ptr<json_component> child;
	bool is_null_value;
	bool is_bool_value;
	bool bool_value;
public:
	jason_value(std::shared_ptr<json_component> parent)
	{
		this->parent = parent;
		is_null_value = true;
		is_bool_value = false;
		bool_value = false;
		child = nullptr;
	}
	jason_value(std::shared_ptr<json_component> parent, bool bool_value)
	{
		this->parent = parent;
		is_null_value = false;
		is_bool_value = true;
		this->bool_value = bool_value;
		child = nullptr
	}
	jason_value(std::shared_ptr<json_component> parent, std::shared_ptr<json_component> child)
	{
		this->parent = parent;
		is_null_value = false;
		is_bool_value = false;
		bool_value = false;
		this->child = child;
	}
	
	// Inherited via json_component
	virtual std::string ToString() override
	{
		if (is_null_value)
		{
			return std::string("null");
		}

		if (is_bool_value)
		{
			return std::string(bool_value);
		}

		return child->ToString();
	}

	virtual std::shared_ptr<json_component> GetParent() override
	{
		return this->parent;
	}

	virtual int GetNumChildren() override
	{
		if (is_null_value || is_bool_value)
		{
			return 0;
		}

		return 1;
	}

	virtual bool TryGetChildAtIndex(int index, std::shared_ptr<json_component> child) override
	{
		if (is_null_value || is_bool_value)
		{
			return false;
		}

		if (index != 0)
		{
			return false;
		}

		child = this->child;

		return true;
	}

};