import 'package:flutter/material.dart';
import 'package:fl_chart/fl_chart.dart';

class SessionStatisticsScreen extends StatefulWidget {
  final String sessionName;

  const SessionStatisticsScreen({super.key, required this.sessionName});

  @override
  State<SessionStatisticsScreen> createState() => _SessionStatisticsScreenState();
}

class _SessionStatisticsScreenState extends State<SessionStatisticsScreen> {
  String viewMode = 'days'; // Default view mode

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('${widget.sessionName} Stats'),
        centerTitle: true,
      ),
      body: SafeArea(
        child: SingleChildScrollView(
          padding: const EdgeInsets.all(16),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              const Text(
                'Overview',
                style: TextStyle(fontSize: 18),
              ),
              const SizedBox(height: 20),
              const Text(
                "Session ran from 10 January to 13 April",
                style: TextStyle(fontSize: 15),
              ),
              const SizedBox(height: 30),

              // Toggle buttons
              Row(
                mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                children: [
                  FloatingActionButton.extended(
                    onPressed: () {
                      setState(() {
                        viewMode = 'days';
                      });
                    },
                    label: const Text("Days"),
                    backgroundColor: viewMode == 'days'
                        ? Colors.green
                        : Colors.grey.shade300,
                    foregroundColor:
                        viewMode == 'days' ? Colors.white : Colors.black,
                  ),
                  FloatingActionButton.extended(
                    onPressed: () {
                      setState(() {
                        viewMode = 'months';
                      });
                    },
                    label: const Text("Months"),
                    backgroundColor: viewMode == 'months'
                        ? Colors.green
                        : Colors.grey.shade300,
                    foregroundColor:
                        viewMode == 'months' ? Colors.white : Colors.black,
                  ),
                ],
              ),

              const SizedBox(height: 10),

              // Summary Container
              Container(
                height: 200,
                width: double.infinity,
                padding: const EdgeInsets.all(20),
                decoration: BoxDecoration(
                  color: Colors.green.shade600,
                  borderRadius: BorderRadius.circular(20),
                ),
                child: Text(
                  viewMode == 'days'
                      ? "Show the tally summary for the period collected in days"
                      : "Show the tally summary for the period collected in months",
                  style: const TextStyle(
                    color: Colors.white,
                    fontSize: 15,
                  ),
                ),
              ),

              const SizedBox(height: 30,),

              Container(
                height: 220,
                width: double.infinity,
                padding: EdgeInsets.all(10),
                decoration: BoxDecoration(
                  color: Colors.green.shade600,
                  borderRadius: BorderRadius.circular(20),
                ),
                child: LineChart(
                  LineChartData(
                    lineBarsData: [
                      LineChartBarData(
                        spots: const [
                          FlSpot(1, 1),
                          FlSpot(2, 1.5),
                          FlSpot(3, 1.4),
                          FlSpot(4, 3.4),
                          FlSpot(5, 2),
                          FlSpot(6, 2.2),
                          FlSpot(7, 1.8),
                        ],
                        isCurved: true,
                        gradient: LinearGradient(
                          colors: [Colors.deepOrange, Colors.deepOrangeAccent],
                        ),
                        barWidth: 4,
                        isStrokeCapRound: true,
                        
                        dotData: FlDotData(show: true),
                      ),
                    ],
                    titlesData: FlTitlesData(
                      leftTitles: AxisTitles(
                        sideTitles: SideTitles(
                          showTitles: true,
                          interval: 1,
                          reservedSize: 32,
                          getTitlesWidget: (value, meta) => Text(
                            value.toString(),
                            style: const TextStyle(color: Colors.black, fontSize: 12),
                          ),
                        ),
                      ),
                      bottomTitles: AxisTitles(
                        sideTitles: SideTitles(
                          showTitles: true,
                          reservedSize: 32,
                          getTitlesWidget: (value, meta) {
                            return Text(
                              'Wk ${value.toInt()}',
                              style: const TextStyle(color: Colors.black, fontSize: 12),
                            );
                          },
                        ),
                      ),
                      topTitles: AxisTitles(sideTitles: SideTitles(showTitles: false)),
                      rightTitles: AxisTitles(sideTitles: SideTitles(showTitles: false)),
                    ),
                    gridData: FlGridData(
                      show: true,
                      drawVerticalLine: true,
                      getDrawingHorizontalLine: (value) => FlLine(
                        color: Colors.white24,
                        strokeWidth: 1,
                      ),
                      getDrawingVerticalLine: (value) => FlLine(
                        color: Colors.white24,
                        strokeWidth: 1,
                      ),
                    ),
                    borderData: FlBorderData(
                      show: true,
                      border: Border.all(color: Colors.white24),
                    ),
                    minX: 1,
                    maxX: 7,
                    minY: 0,
                    maxY: 4,
                  ),
                ),

              ),

              const SizedBox(height: 30,),

              Container(
                height: 200,
                width: double.infinity,
                padding: EdgeInsets.all(20),
                decoration: BoxDecoration(
                  color: Colors.green,
                  borderRadius: BorderRadius.circular(20)
                ),
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    Text(
                      "Summary Statistics",
                      style: TextStyle(
                        fontSize: 20,
                        color: Colors.white
                      ),
                    ),
                    Spacer(),
                    Text(
                      "Most Frequent Activity",
                      style: TextStyle(
                        fontSize: 20,
                        color: Colors.white
                      ),
                    ),
                    Spacer(),
                    Text(
                      "Week Average",
                      style: TextStyle(
                        fontSize: 20,
                        color: Colors.white
                      ),  
                    ),
                  ],
                ),
              )
            ],
          ),
        ),
      ),
    );
  }
}

class CurrentSessionStatisticsScreen extends StatefulWidget {
  final String sessionName;

  const CurrentSessionStatisticsScreen({super.key, required this.sessionName});

  @override
  State<CurrentSessionStatisticsScreen> createState() => _CurrentSessionStatisticsScreen();
}

class _CurrentSessionStatisticsScreen extends State<CurrentSessionStatisticsScreen> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('${widget.sessionName} Stats'),
        centerTitle: true,
      ),
      body: SafeArea(
        child: SingleChildScrollView(
          padding: const EdgeInsets.all(16),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              const Text(
                'Overview',
                style: TextStyle(fontSize: 18),
              ),
              const SizedBox(height: 20),
              const Text(
                "Session ran stared from 10 January and expecteed end to 13 April",
                style: TextStyle(fontSize: 15),
              ),
              const SizedBox(height: 30),
              const Text(
                "Today's Tally Summary",
                style: TextStyle(
                  color: Colors.black,
                  fontSize: 15,
                ),
              ),
              const SizedBox(height: 20),
              Container(
                height: 300,
                width: double.infinity,
                padding: const EdgeInsets.all(20),
                decoration: BoxDecoration(
                  color: Colors.transparent,
                  borderRadius: BorderRadius.circular(20),
                ),
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    buildSummaryRow("Department Name", "20"),
                    const Spacer(),
                    buildSummaryRow("Department Name", "25"),
                    const Spacer(),
                    buildSummaryRow("Department Name", "30"),
                  ],
                ),
              ),
              const SizedBox(height: 20),
              Container(
                width: double.infinity,
                padding: const EdgeInsets.all(20),
                decoration: BoxDecoration(
                  color: Colors.transparent, // Set a visible background color
                  borderRadius: BorderRadius.circular(20),
                ),
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    const Text(
                      "Department Tally Rank",
                      style: TextStyle(
                        fontSize: 20,
                        color: Colors.black,
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                    const SizedBox(height: 20),
                    Container(
                      width: double.infinity,
                      padding: const EdgeInsets.all(16),
                      decoration: BoxDecoration(
                        color: Colors.transparent, // Optional inner styling
                        borderRadius: BorderRadius.circular(16),
                      ),
                      child: Column(
                        crossAxisAlignment: CrossAxisAlignment.start,
                        children: const [
                          Text(
                            "1. Department Name",
                            style: TextStyle(
                              fontSize: 18,
                              color: Colors.black,
                            ),
                          ),
                          SizedBox(height: 12),
                          Text(
                            "2. Department Name",
                            style: TextStyle(
                              fontSize: 18,
                              color: Colors.black,
                            ),
                          ),
                          SizedBox(height: 12),
                          Text(
                            "3. Department Name",
                            style: TextStyle(
                              fontSize: 18,
                              color: Colors.black,
                            ),
                          ),
                        ],
                      ),
                    ),
                  ],
                ),
              ),const SizedBox(height: 20),
              Container(
                width: double.infinity,
                padding: const EdgeInsets.all(20),
                decoration: BoxDecoration(
                  color: Colors.transparent, // Set a visible background color
                  borderRadius: BorderRadius.circular(20),
                ),
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    const Text(
                      "Performnce form Last Activity",
                      style: TextStyle(
                        fontSize: 20,
                        color: Colors.black,
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                    const SizedBox(height: 20),
                    Container(
                      width: double.infinity,
                      padding: const EdgeInsets.all(16),
                      decoration: BoxDecoration(
                        color: Colors.green.shade600, // Optional inner styling
                        borderRadius: BorderRadius.circular(16),
                      ),
                      child: Column(
                        crossAxisAlignment: CrossAxisAlignment.start,
                        children: [
                          buildRankingRow("Department Name", 2),
                          const SizedBox(height: 12),
                          buildRankingRow("Department Name", -1),
                          const SizedBox(height: 12),
                          buildRankingRow("Department Name", 0),
                        ],
                      ),
                    ),
                  ],
                ),
              )
            ],
          ),
        ),
      ),
    );
  }

  Widget buildSummaryRow(String label, String value) {
    return Container(
      height: 70,
      width: double.infinity,
      padding: const EdgeInsets.all(20),
      decoration: BoxDecoration(
        color: Colors.green.shade600,
        borderRadius: BorderRadius.circular(20),
      ),
      child: Row(
        mainAxisAlignment: MainAxisAlignment.spaceBetween,
        children: [
          Text(
            label,
            style: const TextStyle(
              fontSize: 20,
              color: Colors.white,
            ),
          ),
          const Spacer(),
          Text(
            value,
            style: const TextStyle(
              fontSize: 20,
              color: Colors.white,
            ),
          )
        ],
      ),
    );
  }

  Widget buildRankingRow(String department, int rankChange) {
  IconData? icon;
  Color? iconColor;

  if (rankChange > 0) {
    icon = Icons.arrow_upward;
    iconColor = Colors.white;
  } else if (rankChange < 0) {
    icon = Icons.arrow_downward;
    iconColor = Colors.yellow;
  }

  return Row(
    mainAxisAlignment: MainAxisAlignment.spaceBetween,
    children: [
      Text(
        department,
        style: const TextStyle(
          fontSize: 18,
          color: Colors.white,
        ),
      ),
      if (rankChange != 0)
        Row(
          children: [
            Icon(icon, color: iconColor, size: 18),
            const SizedBox(width: 4),
            Text(
              '${rankChange > 0 ? '+' : ''}$rankChange',
              style: TextStyle(
                color: iconColor,
                fontSize: 16,
              ),
            ),
          ],
        ),
    ],
  );
}

}