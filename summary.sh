#!/usr/bin/fish

echo "LeetCode 题目统计"
echo "=================="

# 统计各类题目
set c_count (find . -maxdepth 1 -type d -name "c??-*" | wc -l)
set e_count (find . -maxdepth 1 -type d -name "e??-*" | wc -l)
set in_count (find . -maxdepth 1 -type d -name "in-*" | wc -l)
set total (math $c_count + $e_count + $in_count)

echo "分类题目 (c开头): $c_count"
echo "练习题目 (e开头): $e_count" 
echo "特殊题目 (in开头): $in_count"
echo "题目总计: $total"
echo

# 显示每个分类的详细题目
echo "详细题目列表:"
find . -maxdepth 1 -type d -name "c??-*" -o -name "e??-*" -o -name "in-*" | sort | while read dir
    set problem_name (basename "$dir")
    set file_count (find "$dir" -name "*.cpp" -o -name "*.py" -o -name "*.java" 2>/dev/null | wc -l)
    echo "  $problem_name ($file_count 个源文件)"
end