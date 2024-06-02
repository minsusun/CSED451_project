#include <memory>
#include <ostream>
#include <istream>

#include "glm/vec3.hpp"


struct TransmitTable {
	glm::dvec3* get();
	const glm::dvec3* get() const;
	TransmitTable(std::istream& in);
	const glm::dvec3& operator()(double radius, double consine) const;
	std::unique_ptr<glm::vec3[]> toFloat() const;
private:
	std::unique_ptr<glm::dvec3[]> val;
	TransmitTable(std::unique_ptr<glm::dvec3[]> arr);
	friend TransmitTable bakeTransmitTable();
};
TransmitTable bakeTransmitTable();
static constexpr size_t transmitT_hDim = 512, transmitT_cosDim = 512;
void writeTransmitTableReadable(std::ostream& out, size_t lineLimit, const TransmitTable& table);
void writeTransmitTable(std::ostream& out, const TransmitTable& table);