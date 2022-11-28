#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 3;

int n;
float cx[maxn], cy[maxn], cr[maxn]; 
vector<int> adjs[maxn];

pair<float, float> intervalsIntersect(pair<float, float> interval1, pair<float, float> interval2) {
  return make_pair(max(interval1.first, interval2.first), min(interval1.second, interval2.second));
}

float distance2Points(float x1, float y1, float x2, float y2) {
  float dx = x2 - x1, dy = y2 - y1;

  return sqrt(dx * dx + dy * dy);
}

bool opponetIntersectsOtherOpponent(int opponent1_id, int opponent2_id) {
  return cr[opponent1_id] + cr[opponent2_id] > distance2Points(cx[opponent1_id], cy[opponent1_id], cx[opponent2_id], cy[opponent2_id]);
}

bool opponentIntersectsVerticalLine(int opponent_id, float x_line) {
  return abs(x_line - cx[opponent_id]) < cr[opponent_id];
}

pair<float, float> opponentVerticalLineIntersection(int opponent_id, float x_line) {
  float dx = x_line - cx[opponent_id];
  float dy = sqrt(cr[opponent_id] * cr[opponent_id] - dx * dx);
  
  return make_pair(cy[opponent_id] - dy, cy[opponent_id] + dy);
}

vector<pair<float, float> > removeIntervalFromIntervalsList(vector<pair<float, float> > intervals, float interval_start, float interval_end) {
  vector<int> toBeDeletedIndices;
  vector<pair<float, float> > toBeAddedIntervals;
  vector<pair<float, float> > resultIntervalsList;

  for (int i = 0; i < intervals.size(); i++) {
    float existed_interval_start = intervals[i].first;
    float existed_interval_end = intervals[i].second;

    if (existed_interval_start >= interval_end || interval_start >= existed_interval_end ) {
      resultIntervalsList.push_back(intervals[i]);
      continue;
    }

    // intersect i should not be added to the result list
    if (existed_interval_start <= interval_start) {
      resultIntervalsList.push_back(make_pair(existed_interval_start, interval_start));
    }
    if (interval_end <= existed_interval_end) {
      resultIntervalsList.push_back(make_pair(interval_end, existed_interval_end));
    }
  }
  sort(resultIntervalsList.begin(), resultIntervalsList.end());

  return resultIntervalsList;
}

void createGraphOfOpponents() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }

      if (opponetIntersectsOtherOpponent(i, j)) {
        adjs[i].push_back(j), adjs[j].push_back(i);
      }
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> cx[i] >> cy[i] >> cr[i];
  }
}