import 'package:flutter/material.dart';
import 'package:talli_app/Screens/session_statistics_screen.dart';

class ReportScreen extends StatelessWidget {
  const ReportScreen({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: const Color(0xFFF5F6FA), // Light grey background
      appBar: AppBar(
        backgroundColor: Colors.white,
        elevation: 0,
        title: const Text(
          "Summary Report",
          style: TextStyle(
            color: Colors.black87,
            fontWeight: FontWeight.bold,
            fontSize: 24,
          ),
        ),
        centerTitle: true,
      ),
      body: SafeArea(
        child: SingleChildScrollView(
          padding: const EdgeInsets.all(16),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              _sectionHeader("Current Session", "All Records"),
              const SizedBox(height: 16),
              _sessionCard(
                "Midterm Session", 
                Colors.green.shade700, 
                () {
                  Navigator.push(
                    context,
                    MaterialPageRoute(
                      builder: (_) => CurrentSessionStatisticsScreen(sessionName: "Midterm Session"),
                    ),
                  );
                }),

              const SizedBox(height: 32),
              _sectionHeader("History", "All Records"),
              const SizedBox(height: 16),
              _sessionCard(
                "Session A", 
                Colors.green.shade600, 
                () {
                  Navigator.push(
                    context,
                    MaterialPageRoute(
                      builder: (_) => SessionStatisticsScreen(sessionName: "Session A"),
                    ),
                  );
                }
              ),
              const SizedBox(height: 16),
              _sessionCard(
                "Session B", 
                Colors.green.shade600, 
                () {
                  Navigator.push(
                    context,
                    MaterialPageRoute(
                      builder: (_) => SessionStatisticsScreen(sessionName: "Session B"),
                    ),
                  );
                }
              ),

            ],
          ),
        ),
      ),
    );
  }

  Widget _sectionHeader(String title, String actionText) {
    return Row(
      mainAxisAlignment: MainAxisAlignment.spaceBetween,
      children: [
        Text(
          title,
          style: const TextStyle(
            fontSize: 18,
            fontWeight: FontWeight.w600,
          ),
        ),
        Text(
          actionText,
          style: TextStyle(
            fontSize: 14,
            color: Colors.blue.shade700,
            fontWeight: FontWeight.w500,
          ),
        ),
      ],
    );
  }

  Widget _sessionCard(String sessionName, Color backgroundColor, VoidCallback onArrowPressed) {
    return Container(
      height: 100,
      padding: const EdgeInsets.all(16),
      decoration: BoxDecoration(
        color: backgroundColor,
        borderRadius: BorderRadius.circular(20),
        boxShadow: [
          BoxShadow(
            color: backgroundColor,
            blurRadius: 12,
            offset: const Offset(0, 6),
          )
        ],
      ),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          // 🔹 Row with title and arrow button
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceBetween,
            children: [
              Text(
                sessionName,
                style: const TextStyle(
                  fontSize: 20,
                  color: Colors.white,
                  fontWeight: FontWeight.bold,
                ),
              ),
              IconButton(
                onPressed: onArrowPressed,
                icon: const Icon(Icons.arrow_forward, color: Colors.white, size: 18),
                padding: EdgeInsets.zero,
                constraints: BoxConstraints(), // Removes default spacing
              ),
            ],
          ),
          const Spacer(),
          const Text(
            "View statistics and reports for this session",
            style: TextStyle(
              color: Colors.white70,
              fontSize: 14,
            ),
          )
        ],
      ),
    );
  }
}