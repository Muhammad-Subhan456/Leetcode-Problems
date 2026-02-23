class Solution {
public:

vector<string> split(const string &s, char c) {
    vector<string> tokens;
    string token;
    stringstream ss(s);

    while (getline(ss, token, c)) {
        tokens.push_back(token);
    }

    return tokens;
}

bool validIPv4(string IP){
    if(count(IP.begin(),IP.end(),'.') != 3) return false;
    vector<string>parts = split(IP,'.');
    if(parts.size()!= 4) return false;
    for(auto part : parts){
        if(part.empty() || part.size()>3 || part.size()>1 && part[0] == '0') return false;
        for(auto c : part){
            if(!isdigit(c)) return  false;
        }
        if(stoi(part) > 255) return false;
            
    }
    return true;
}

bool validIP6(string IP){
    if(count(IP.begin(),IP.end(),':') != 7) return false;
    vector<string>parts = split(IP,':');
    if(parts.size() != 8) return false;
    for(auto part : parts){
        if(part.empty() || part.size() > 4) return false;
    for(auto c : part){
        if(!isdigit(c) && ((!isalpha(c)) || toupper(c) > 'F')) return false;
    }
    }
    return true;
}

string validIPAddress(string queryIP) {
    if(validIPv4(queryIP)) return "IPv4";
    else if(validIP6(queryIP)) return "IPv6";
    return "Neither";

    }
};