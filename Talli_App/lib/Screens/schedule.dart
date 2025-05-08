import 'package:flutter/material.dart';

class ScheduleScreen extends StatefulWidget {
  const ScheduleScreen({super.key});

  @override
  State<ScheduleScreen> createState() => _ScheduleScreenState();
}

class _ScheduleScreenState extends State<ScheduleScreen> {
  int selectedIndex = 2;

  final List<Map<String, String>> days = [
    {'day': 'Fri', 'date': '31'},
    {'day': 'Sat', 'date': '01'},
    {'day': 'Sun', 'date': '02'},
    {'day': 'Mon', 'date': '03'},
    {'day': 'Tue', 'date': '04'},
    {'day': 'Wed', 'date': '05'},
    {'day': 'Thu', 'date': '06'},
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.grey.shade100,
      appBar: AppBar(
        backgroundColor: Colors.white,
        elevation: 0,
        title: const Text(
          "Schedule",
          style: TextStyle(
            fontSize: 22,
            color: Colors.black87,
            fontWeight: FontWeight.bold,
          ),
        ),
        centerTitle: true,
        actions: [
          Padding(
            padding: const EdgeInsets.only(right: 16),
            child: Icon(Icons.calendar_today, color: Colors.black87, size: 20),
          ),
        ],
      ),
      body: SafeArea(
        child: SingleChildScrollView(
          padding: const EdgeInsets.all(20.0),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              /// 🔄 Horizontal Date Picker
              SizedBox(
                height: 90,
                child: Row(
                  children: [
                    IconButton(
                      icon: const Icon(Icons.arrow_back_ios_new),
                      onPressed: () {
                        // Handle previous dates
                      },
                    ),
                    Expanded(
                      child: ListView.separated(
                        scrollDirection: Axis.horizontal,
                        itemCount: days.length,
                        separatorBuilder: (_, __) => const SizedBox(width: 10),
                        itemBuilder: (context, index) {
                          bool isSelected = selectedIndex == index;
                          return GestureDetector(
                            onTap: () {
                              setState(() {
                                selectedIndex = index;
                              });
                            },
                            child: Container(
                              width: 60,
                              padding: const EdgeInsets.symmetric(vertical: 10),
                              decoration: BoxDecoration(
                                color: isSelected
                                    ? Colors.deepOrange
                                    : Colors.transparent,
                                borderRadius: BorderRadius.circular(12),
                              ),
                              child: Column(
                                mainAxisAlignment: MainAxisAlignment.center,
                                children: [
                                  Text(
                                    days[index]['day']!,
                                    style: TextStyle(
                                      color: isSelected
                                          ? Colors.white
                                          : Colors.green.shade700,
                                    ),
                                  ),
                                  const SizedBox(height: 4),
                                  Text(
                                    days[index]['date']!,
                                    style: TextStyle(
                                      fontSize: 18,
                                      fontWeight: FontWeight.bold,
                                      color: isSelected
                                          ? Colors.white
                                          : Colors.green.shade700,
                                    ),
                                  ),
                                ],
                              ),
                            ),
                          );
                        },
                      ),
                    ),
                    IconButton(
                      icon: const Icon(Icons.arrow_forward_ios),
                      onPressed: () {
                        // Handle next dates
                      },
                    ),
                  ],
                ),
              ),

              const SizedBox(height: 30),

              Text(
                '${days[selectedIndex]['day']} ${days[selectedIndex]['date']}',
                style: const TextStyle(
                  fontSize: 18,
                  fontWeight: FontWeight.bold,
                ),
              ),

              const SizedBox(height: 20),

              _sessionCard(
                context,
                title: "No Scheduled Activity Today",
              ),

              const SizedBox(height: 30),

              const Text(
                "Session",
                style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold),
              ),

              const SizedBox(height: 20),

              _sessionCard(
                context,
                title: "No Schedule Session",
                
                buttonIcon: Icons.add,
                buttonAction: () {
                  // Handle add new session
                },
              ),
            ],
          ),
        ),
      ),
    );
  }

  /// 🧩 Reusable session card
  Widget _sessionCard(BuildContext context,
      {required String title, IconData? buttonIcon, VoidCallback? buttonAction}) {
    return Container(
      height: 180,
      width: double.infinity,
      padding: const EdgeInsets.all(16),
      decoration: BoxDecoration(
        color: Colors.green.shade700,
        borderRadius: BorderRadius.circular(20),
        boxShadow: [
          BoxShadow(
            color: Colors.green.shade700,
            blurRadius: 12,
            offset: const Offset(0, 6),
          )
        ],
      ),
      child: Stack(
        children: [
          Align(
          alignment: Alignment.centerLeft,
          child: Text(
            "Set a schedule to start tracking you tally",
            style: TextStyle(
              color: Colors.white
            ),
          ),

          ),
          Align(
            alignment: Alignment.topLeft,
            child: Text(
              title,
              style: const TextStyle(
                color: Colors.white,
                fontSize: 20,
              ),
            ),
          ),
          if (buttonIcon != null && buttonAction != null)
            Align(
              alignment: Alignment.bottomRight,
              child: ElevatedButton(
                onPressed: buttonAction,
                style: ElevatedButton.styleFrom(
                  backgroundColor: Colors.white,
                  shape: const CircleBorder(),
                  padding: const EdgeInsets.all(12),
                ),
                child: Icon(
                  buttonIcon,
                  color: Colors.deepOrange,
                  size: 24,
                ),
              ),
            ),
        ],
      ),
    );
  }
}
