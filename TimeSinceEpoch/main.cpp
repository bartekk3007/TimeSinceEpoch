#include <iostream>
#include <chrono>
#include <iomanip>

int main()
{
	std::chrono::system_clock::time_point timePoint = std::chrono::system_clock::now();
	std::chrono::system_clock::duration dur = timePoint.time_since_epoch();

	std::cout << "Time since epoch " << dur.count() << '\n';
	std::cout << std::setw(19) << dur.count() << '\n';
	std::cout << std::setw(19) << dur.max().count() << '\n';

	std::cout << dur / std::chrono::seconds(1) << '\n';

	auto milliPoint = std::chrono::time_point_cast<std::chrono::milliseconds>(timePoint);
	std::cout << milliPoint.time_since_epoch().count() << '\n';

	auto distanceHours = std::chrono::time_point_cast<std::chrono::hours>(std::chrono::system_clock::now()).
							time_since_epoch().count();

	std::cout << "Hours since epoch: " << distanceHours << '\n';

	std::chrono::system_clock systemClock;
	std::chrono::steady_clock steadyClock;
	std::cout << std::boolalpha << "System clock is steady - " << systemClock.is_steady << '\n';
	std::cout << std::boolalpha << "Steady clock is steady - " << steadyClock.is_steady << '\n';

	return 0;
}